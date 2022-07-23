#include "subject.h"

void Subject::Attach(Observer* observer) { observers_.push_back(observer); }

// NOTE: std::list remove's complexity = Linear in the size of the container
void Subject::Detach(Observer* observer) { observers_.remove(observer); }
