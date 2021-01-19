//
// Created by umar on 19/1/21.
//

#include "mutexlock.h"


MutexLock MutexLock::instance;

MutexLock &MutexLock::getInstance() {
    return instance;
}

bool MutexLock::tryLock() {
    return m_mutexLock.try_lock();
}

bool MutexLock::acquireLock() {
    m_mutexLock.lock();
    return true;
}

bool MutexLock::releaseLock() {
    m_mutexLock.unlock();
    return true;
}
