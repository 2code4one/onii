#include <iostream>
#include "onii/onii.hpp"

class bot;

class walk :
    public onii::ai::fsm::state<bot, walk>
{
public:

    virtual void execute(bot *b);
};

class rest :
    public onii::ai::fsm::state<bot, rest>
{
public:

    virtual void execute(bot *b);
};

class bot :
    public onii::ai::fsm::state_machine<bot>
{
public:

    bot() :
        onii::ai::fsm::state_machine<bot>(this)
    {
        fsm()->set_state(walk::instance());
    }

    void update()
    {
        fsm()->update();
    }
};

void walk::execute(bot *b)
{
    std::cout << "walk" << std::endl;
    b->fsm()->set_state(rest::instance());
}

void rest::execute(bot *b)
{
    std::cout << "rest" << std::endl;
    b->fsm()->set_state(walk::instance());
}

int main()
{
    bot a;
    while(1)
    {
        a.update();
        onii::sleep(0.2);
    }

    return 0;
}
