#include "second-task.h"

namespace Second{

	char* serialize(List* list) {
		size_t pos = 0;
		char* buffer = new char[1];
		do {
			pos += sprintf_s(buffer + pos, 12, "%d/", list->payload);
			list = list->next;
		} while (list);
		sprintf_s(buffer + pos, 2, "%c", '\\');
		return buffer;
	}

	List* deserialize(char* data) {
		List* head = NULL;
		List* cur = NULL;
		std::string s_data = "";
		size_t pos = 0;
		while (data[pos] != '\\') {
			List* tmp = new List;
			s_data = "";
			while (data[pos] != '/') {
				s_data += data[pos];
				pos++;
			}

			tmp->next = NULL;
			tmp->payload = stoi(s_data);
			if (!head) {
				head = tmp;
				cur = head;
			}
			else {
				cur->next = tmp;
				cur = cur->next;
			}
			pos++;
		}

		return head;
	}
}