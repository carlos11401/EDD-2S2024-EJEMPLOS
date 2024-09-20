#include "page.h"
Page::Page() {
  for (int i = 0; i < degree; i++) {
      keys[i] = 0;
  }

  for (int i = 0; i < degree; i++) {
      branches[i] = nullptr;
  }

  count = 0;
}

bool Page::fullPage(){
	return this->count == degree-1;
}