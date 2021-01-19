//
// Created by umar on 19/1/21.
//

#ifndef P2P_CPP_MUTEXLOCK_H
#define P2P_CPP_MUTEXLOCK_H

#include <mutex>

class MutexLock {

    std::mutex m_mutexLock;

    MutexLock() = default;

public:
    static MutexLock instance;

    static MutexLock &getInstance();

    bool tryLock();

    bool acquireLock();

    bool releaseLock();
};


#endif //P2P_CPP_MUTEXLOCK_H
