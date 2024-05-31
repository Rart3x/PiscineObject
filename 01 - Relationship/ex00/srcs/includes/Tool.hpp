#pragma once

#include "Worker.hpp"

#include <iostream>

class Worker;

class Tool {

    public:
        Tool();
        virtual ~Tool();

        virtual void        use() = 0;
                
        virtual std::string getStr() const = 0;        
        virtual Worker*     getWorker() = 0;

        virtual void        setWorker(Worker* worker) = 0;
        virtual void        setEquiped() = 0;

    private:
};