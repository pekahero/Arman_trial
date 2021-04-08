#pragma once

#include <cstdio>
#include <string>

namespace Second {
	struct List {
		List* next;
		int payload;
	};
	char* serialize(List* list);
	List* deserialize(char* data);
}