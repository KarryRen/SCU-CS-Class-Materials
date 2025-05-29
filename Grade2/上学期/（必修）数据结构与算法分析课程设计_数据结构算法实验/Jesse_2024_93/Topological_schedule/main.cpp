#include "topological_lesson.h"

int main()
{
    topological_lesson lesson;
    lesson.load();
    lesson.graph_generate();
    lesson.topological_sort();
    lesson.print();
    return 0;
}
