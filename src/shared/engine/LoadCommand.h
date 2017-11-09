// Generated by dia2code
#ifndef ENGINE__LOADCOMMAND__H
#define ENGINE__LOADCOMMAND__H

#include <string>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "CommandTypeId.h"
#include "Command.h"

namespace engine {

  /// class LoadCommand - 
  class LoadCommand : public engine::Command {
    // Attributes
  protected:
    std::string file_name;
    // Operations
  public:
    LoadCommand ();
    CommandTypeId getTypeId () const;
    void execute (state::State& state);
    // Setters and Getters
    const std::string& getFile_name() const;
    void setFile_name(const std::string& file_name);
  };

};

#endif
