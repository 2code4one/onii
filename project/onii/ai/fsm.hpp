#ifndef ONII_AI_FSM_HPP
#define ONII_AI_FSM_HPP

/////////////////////////////////////////////////
/// @file onii/ai/fsm.hpp
/////////////////////////////////////////////////

#include "detail/fsm.hpp"

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
template<typename EntityT, typename StateT = void>
class state :
    public detail::base_state<EntityT>
{
public:

    static StateT *instance()
    {
        static StateT state_instance;
        return &state_instance;
    }

};

template<typename EntityT>
class state<EntityT, void> :
    public detail::base_state<EntityT>
{};

template<typename EntityT, bool DynamicState = false>
class state_machine
{
public:

    state_machine(EntityT *entity_owner) :
        m_impl(entity_owner)
    {}

    virtual ~state_machine()
    {}

    detail::state_machine_impl<EntityT, DynamicState> *fsm()
    {
        return &m_impl;
    }

private:

    detail::state_machine_impl<EntityT, DynamicState> m_impl;
}; // class state_machine
} // namespace fsm
} // namespace ai
} // namespace onii

#endif // ONII_AI_FSM_HPP
