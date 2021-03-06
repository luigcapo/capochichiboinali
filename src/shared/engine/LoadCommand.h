// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H

#include <string>
#include <stack>
#include <json/json.h>

namespace state {
  class State;
};
namespace engine {
  class Action;
  class LoadCommand;
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
    std::string file_name_map;
    std::string file_name_grid;
    // Operations
  public:
    LoadCommand (const std::string& mapCSV, const std::string& gridCSV);
    CommandTypeId getTypeId () const;
    void execute (state::State& state, std::stack<Action*>& s);
    void serialized (Json::Value& out) const;
    static LoadCommand* deserialized (Json::Value& in);
    // Setters and Getters
    const std::string& getFile_name_map() const;
    void setFile_name_map(const std::string& file_name_map);
    const std::string& getFile_name_grid() const;
    void setFile_name_grid(const std::string& file_name_grid);
  };

};

#endif
