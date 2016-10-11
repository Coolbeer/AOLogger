#ifndef T_EVENT_H
#define T_EVENT_H

#include <string>

namespace k_event
{
    enum k_type { damage, heal };
}

class t_event
{
    public:
        t_event();
        virtual k_event::k_type     type(void) = 0;
        std::string                 getSource(void);
        std::string                 getTarget(void);
        void                        setSource(const std::string &newSource);
        void                        setTarget(const std::string &newTarget);
    private:
        std::string                 source;
        std::string                 target;
};

#endif // T_EVENT_H
