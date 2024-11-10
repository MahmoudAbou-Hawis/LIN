#ifndef LINNOTIFIER_H_
#define LINNOTIFIER_H_

#include "interfaces/abstractNotifier.hpp"
#include "States/LinStates/LinConnection.hpp"

class RNotifier : public Notifier
{
    private:
        RNotifier(){};
    public:
        static RNotifier& getInstance() {
            static RNotifier instance;
            return instance;
        }
        void notify(LinConnection* s) override;
        
};
#endif
