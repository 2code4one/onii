#ifndef ONII_AI_FSM_HPP
#define ONII_AI_FSM_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fsm.hpp
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @namespace onii
/////////////////////////////////////////////////
namespace onii
{
/////////////////////////////////////////////////
/// @namespace onii::ai
/////////////////////////////////////////////////
namespace ai
{
/////////////////////////////////////////////////
/// @namespace onii::ai::fsm
/////////////////////////////////////////////////
namespace fsm
{
/////////////////////////////////////////////////
/// @namespace onii::ai::fsm::detail
/// @remarks This namespace is not intended to be used by users
/////////////////////////////////////////////////
namespace detail
{
/////////////////////////////////////////////////
/// @class base_state
/// @brief Base class for state implementation
/// @remarks This class is not intended to be used by users
/// @see onii::ai::fsm::state instead
/////////////////////////////////////////////////
template<typename EntityT>
class base_state
{
public:

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    virtual ~base_state()
    {}

    /////////////////////////////////////////////////
    /// @brief Function called at state entrance
    ///
    /// @param[in,out] entity - Derived class of onii::ai::fsm::state_machine
    /////////////////////////////////////////////////
    virtual void enter(EntityT *)
    {}

    /////////////////////////////////////////////////
    /// @brief Function called at state exit
    ///
    /// @param[in,out] entity - Derived class of onii::ai::fsm::state_machine
    /////////////////////////////////////////////////
    virtual void exit(EntityT *)
    {}

    /////////////////////////////////////////////////
    /// @brief Function called at each entity update
    ///
    /// @param[in,out] entity - Derived class of onii::ai::fsm::state_machine
    /////////////////////////////////////////////////
    virtual void execute(EntityT *) = 0;

};

/////////////////////////////////////////////////
/// @class state_machine_impl
/// @brief Base class for state machine implementation
/// @remarks This class is not intended to be used by users
/// @see onii::ai::fsm::state_machine instead
/////////////////////////////////////////////////
template<typename EntityT, bool DynamicState>
class state_machine_impl
{
public:

    /////////////////////////////////////////////////
    /// @brief Constructor
    ///
    /// @param[in,out] entity_owner - The derived class of state_machine
    /////////////////////////////////////////////////
    state_machine_impl(EntityT *entity_owner) :
        m_entity_owner(entity_owner),
        m_current_state(nullptr),
        m_previous_state(nullptr),
        m_global_state(nullptr)
    {}

    /////////////////////////////////////////////////
    /// @brief Copy contructor
    /////////////////////////////////////////////////
    state_machine_impl(state_machine_impl const &other) = delete;

    /////////////////////////////////////////////////
    /// @brief Affectation operator
    /////////////////////////////////////////////////
    state_machine_impl &operator=(state_machine_impl const &other) = delete;

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    virtual ~state_machine_impl()
    {
        if(DynamicState)
        {
            delete m_current_state;
            delete m_previous_state;
            delete m_global_state;
        }
    }

    /////////////////////////////////////////////////
    /// @brief Change the current state
    ///
    /// @param[in,out] new_state - A pointer to the new state
    /////////////////////////////////////////////////
    void set_state(base_state<EntityT> *new_state)
    {
        if(m_current_state)
            m_current_state->exit(m_entity_owner);
        if(DynamicState)
            delete m_previous_state;
        m_previous_state = m_current_state;
        m_current_state = new_state;
        if(m_current_state)
            m_current_state->enter(m_entity_owner);
    }

    /////////////////////////////////////////////////
    /// @brief Change the global state
    ///
    /// @param[in,out] new_state - A pointer to the new state
    /////////////////////////////////////////////////
    void set_global_state(base_state<EntityT> *new_state)
    {
        if(m_global_state)
            m_global_state->exit(m_entity_owner);
        if(DynamicState)
            delete m_global_state;
        m_global_state = new_state;
        if(m_global_state)
            m_global_state->enter(m_entity_owner);
    }

    /////////////////////////////////////////////////
    /// @brief Change the current state to the previous one
    ///
    /// @remarks The internal pointer to the previous state must be valid
    /////////////////////////////////////////////////
    void back_to_previous_state()
    {
        set_state(m_previous_state);
    }

    /////////////////////////////////////////////////
    /// @brief Update the state machine
    /////////////////////////////////////////////////
    void update()
    {
        if(m_global_state)
            m_global_state->execute(m_entity_owner);
        if(m_current_state)
            m_current_state->execute(m_entity_owner);
    }

private:

    // Data members
    EntityT *m_entity_owner;
    base_state<EntityT> *m_current_state;
    base_state<EntityT> *m_previous_state;
    base_state<EntityT> *m_global_state;

}; // class state_machine
} // namespace detail

/////////////////////////////////////////////////
/// @class state
/// @brief Base class for state implementation
/////////////////////////////////////////////////
template<typename EntityT, typename StateT = void>
class state :
    public detail::base_state<EntityT>
{
public:

    /////////////////////////////////////////////////
    /// @brief Return a static instance of StateT
    ///
    /// @return A pointer to a static instance of StateT
    /// @remarks If the template parameter StateT is not defined (void),
    ///          then this function does not exist !
    /////////////////////////////////////////////////
    static StateT *instance()
    {
        static StateT state_instance;
        return &state_instance;
    }

};

/////////////////////////////////////////////////
/// @cond IGNORE
template<typename EntityT>
class state<EntityT, void> :
    public detail::base_state<EntityT>
{};
/// @endcond
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// @class state_machine
/// @brief Base class for state machine implementation
/// @remarks If the template parameter DynamicState is true,
///          then states will be automatically delleted by the state machine
/////////////////////////////////////////////////
template<typename EntityT, bool DynamicState = false>
class state_machine
{
public:

    /////////////////////////////////////////////////
    /// @brief Contructor
    ///
    /// @param[in,out] entity_owner - A pointer to the instance of the derived class
    /////////////////////////////////////////////////
    state_machine(EntityT *entity_owner) :
        m_impl(entity_owner)
    {}

    /////////////////////////////////////////////////
    /// @brief Destructor
    /////////////////////////////////////////////////
    virtual ~state_machine()
    {}

    /////////////////////////////////////////////////
    /// @brief Get the internal state machine
    ///
    /// @return A pointer to the internal state machine
    /// @see onii::ai::fsm::detail::state_machine_impl
    /////////////////////////////////////////////////
    detail::state_machine_impl<EntityT, DynamicState> *fsm()
    {
        return &m_impl;
    }

private:

    // Data members
    detail::state_machine_impl<EntityT, DynamicState> m_impl;
}; // class state_machine
} // namespace fsm
} // namespace ai
} // namespace onii

#endif // ONII_AI_FSM_HPP
