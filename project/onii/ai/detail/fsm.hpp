#ifndef ONII_AI_DETAIL_FSM_HPP
#define ONII_AI_DETAIL_FSM_HPP

namespace onii
{
namespace ai
{
namespace fsm
{
namespace detail
{
template<typename EntityT>
class base_state
{
public:

    virtual ~base_state()
    {}

    virtual void enter(EntityT *)
    {}

    virtual void exit(EntityT *)
    {}

    virtual void execute(EntityT *) = 0;

};

template<typename EntityT, bool DynamicState>
class state_machine_impl
{
public:

    state_machine_impl(EntityT *entity_owner) :
        m_entity_owner(entity_owner),
        m_current_state(nullptr),
        m_previous_state(nullptr),
        m_global_state(nullptr)
    {}

    state_machine_impl(state_machine_impl const &other) = delete;
    state_machine_impl &operator=(state_machine_impl const &other) = delete;

    virtual ~state_machine_impl()
    {
        if(DynamicState)
        {
            delete m_current_state;
            delete m_previous_state;
            delete m_global_state;
        }
    }

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

    void back_to_previous_state()
    {
        set_state(m_previous_state);
    }

    void update()
    {
        if(m_global_state)
            m_global_state->execute(m_entity_owner);
        if(m_current_state)
            m_current_state->execute(m_entity_owner);
    }

private:

    EntityT *m_entity_owner;
    base_state<EntityT> *m_current_state;
    base_state<EntityT> *m_previous_state;
    base_state<EntityT> *m_global_state;

}; // class state_machine
}
}
}
}

#endif // ONII_AI_DETAIL_FSM_HPP
