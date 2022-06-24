#include "PlayerObject.h"
#include <iostream>
using namespace std;

PlayerObject::PlayerObject()
{
    is_falling_ = false;
    y_val_ = 0;
    num = 0;
}

PlayerObject::~PlayerObject()
{
  Free();
}

void PlayerObject::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
  if( events.type == SDL_KEYDOWN ) {
    switch( events.key.keysym.sym ) {
    case SDLK_UP:
      {
        if (is_falling_ == false) {
            y_val_ = -10;
        }
      }
      break;
//    case SDLK_DOWN:
//      {
//        if (is_falling_ == false) {
//            y_val_ = -100;
//        }
//      }
    }
  }
  else if( events.type == SDL_KEYUP ) {
    switch( events.key.keysym.sym ) {
//    case SDLK_UP:
//        {
//            if (is_falling_ == false) {
//                y_val_ = 0;
//            }
//        }
//        break;
    case SDLK_DOWN:
        {
            if (is_falling_ == false) {
                y_val_ = 10;
            } //else {
////                y_val_ = 5;
////            }
        }
        break;
    }
  }
  else if(is_falling_ == true) {
        y_val_ = 5;
  }
}


bool PlayerObject::LoadImg(std::string path, SDL_Renderer* screen)
{
  //bool ret = BaseObject::LoadImageFile(path, screen);
  return BaseObject::LoadImageFile(path, screen);
}

void PlayerObject::Show(SDL_Renderer* des)
{
   BaseObject::Render(des);
}

void PlayerObject::DoFalling(SDL_Renderer* des)
{
    rect_.y += y_val_;
    cout << y_val_ <<endl;
    if (is_falling_ != true && num > 3) {
        y_val_ = 0;
        num = 0;
    } else if (is_falling_ != true && num <= 3) {
        num++;
    } else {
        y_val_ = 5;
    }
    if ((rect_.y + rect_.h) >= GROUND_MAP) {
        LoadImg("img//gwedly111.png", des);
        is_falling_ = true;
        DoGround(des);
    }
}

void PlayerObject::DoGround(SDL_Renderer* screen)
{
    y_val_ = 0;
    rect_.y = GROUND_MAP - rect_.h;
    is_die_ = true;
}
