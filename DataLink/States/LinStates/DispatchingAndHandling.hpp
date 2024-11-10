#ifndef DISPATCHINGANDHANDLING_H_
#define DISPATCHINGANDHANDLING_H_

#include "interfaces/abstractLinState.hpp"
#include "interfaces/abstractedframedespatcher.hpp"
#include "interfaces/abstractNotifier.hpp"
#include "interfaces/abstracttransportadabter.hpp"

class DispatchingAndHandling : public LinsStates
{
    private:
        DispatchingAndHandling(){};
    public:
        void handle() override;
        friend void Handler(DispatchingAndHandling*);
        void set(AbstractedFramedDispatcher * disp,LinConnection * con ,AbstractTranspoertAdabter * Tb );
        static DispatchingAndHandling &getInstance()
        {
            static DispatchingAndHandling Instance;
            return Instance;
        }
    private:
        AbstractedFramedDispatcher * mDispatcher{nullptr};
        LinConnection * mConnection;
        AbstractTranspoertAdabter * mTb;
};

#endif
