#ifndef T_EVENT_H
#define T_EVENT_H

#include <string>

namespace k_event
{
    enum k_type { damage, heal, loot, deleteItem, error };
}

class t_event
{
    public:
        t_event();
        virtual k_event::k_type     type(void) = 0;
        std::string                 getSource(void);
        std::string                 getTarget(void);
        uint64_t                    getTimeStamp(void);
        void                        setSource(const std::string &newSource);
        void                        setTarget(const std::string &newTarget);
        void                        setTimeStamp(const uint64_t &tStamp);
    private:
        std::string                 source;
        std::string                 target;
        uint64_t                    timeStamp = 0;

};

#endif // T_EVENT_H
