#include "script_store.h"
#include <string.h>

namespace Code {

constexpr char ScriptStore::k_scriptExtension[];
int ScriptStore::k_minusInExamMode = 0;

void ScriptStore::setKMinusInExamMode(int value) {
  k_minusInExamMode = value;
}

/*void ScriptStore::examRename(int value) {
  char extension[];
  if (value==1) {
    extension = ".txtInExam"
    for(size_t i = 0; i < (size_t)Ion::Storage::sharedStorage()->numberOfRecordsWithExtension("py"); i++) {
      // TODO : rename all .py files in .txtInExamMode file. 
    }
  } else {
    extension = ".py"
    // TODO : rename all .txtInExamMode files in .py file. 
  }
}
*/


bool ScriptStore::ScriptNameIsFree(const char * baseName) {
  return ScriptBaseNamed(baseName).isNull();
}

// Here we add "base" script
ScriptStore::ScriptStore() {
  addScriptFromTemplate(ScriptTemplate::Perf());
}

void ScriptStore::deleteAllScripts() {
  for (int i = numberOfScripts() - 1; i >= 0; i--) {
    scriptAtIndex(i).destroy();
  }
}

bool ScriptStore::isFull() {
  return Ion::Storage::sharedStorage()->availableSize() < k_fullFreeSpaceSizeLimit;
}

const char * ScriptStore::contentOfScript(const char * name, bool markAsFetched) {
  Script script = ScriptNamed(name);
  if (script.isNull()) {
    return nullptr;
  }
  if (markAsFetched) {
    script.setFetchedFromConsole(true);
  }
  return script.content();
}

void ScriptStore::clearVariableBoxFetchInformation() {
  // TODO optimize fetches
  const int scriptsCount = numberOfScripts();
  for (int i = 0; i < scriptsCount; i++) {
    scriptAtIndex(i).setFetchedForVariableBox(false);
  }
}

void ScriptStore::clearConsoleFetchInformation() {
  // TODO optimize fetches
  const int scriptsCount = numberOfScripts();
  for (int i = 0; i < scriptsCount; i++) {
    scriptAtIndex(i).setFetchedFromConsole(false);
  }
}

Script::ErrorStatus ScriptStore::addScriptFromTemplate(const ScriptTemplate * scriptTemplate) {
  size_t valueSize = Script::StatusSize() + strlen(scriptTemplate->content()) + 1; // (auto importation status + content fetched status) + scriptcontent size + null-terminating char
  assert(Script::nameCompliant(scriptTemplate->name()));
  Script::ErrorStatus err = Ion::Storage::sharedStorage()->createRecordWithFullName(scriptTemplate->name(), scriptTemplate->value(), valueSize);
  assert(err != Script::ErrorStatus::NonCompliantName);
  return err;
}

}
