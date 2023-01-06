#include "Skeleton.h"
USING_NS_CC;

Skeleton::Skeleton():Enemy()
{
    int frameBegin = 0;
    int frameEnd = 3;
    float frameDelay = 0.15f;
    this->setSpriteFrame(SKELETON_IDLE, frameBegin, true);
    this->setAnimation(REPEAT::FOREVER, SKELETON_IDLE, frameBegin, frameEnd, frameDelay);
}

Skeleton::~Skeleton()
{
}
