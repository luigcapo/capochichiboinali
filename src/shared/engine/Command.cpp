/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include  "Command.h"
#include "AttaqueCommand.h"
#include "MoveCommand.h"
#include "LoadCommand.h"

namespace engine{

    Command::~Command() {

    }

    Command* Command::deserialized(Json::Value& in) {
        switch (in.get("Command",0).asInt()){
            case 1:
                return LoadCommand::deserialized(in);
                break;
            case 2:
                return MoveCommand::deserialized(in);
                break;
            case 3:
                return AttaqueCommand::deserialized(in);
                break;
            default:
                return NULL;
                break;
                        
        }
    }

}