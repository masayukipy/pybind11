#include <pybind11/pybind11.h>

namespace py = pybind11;

int add (int i=1, int j=2) {
    return i + j;
}

int min (int i, int j) {
    return i - j;
}


PYBIND11_MODULE(example, m) {
    m.attr("the_answer") = 42;

    py::object world = py::cast("world");

    m.attr("what") = world;

    m.doc() = "pybind11 example plugin";  // optional module docstring

    m.def("add", &add, "A function that add two numbers", py::arg("i") = 1, py::arg("j") = 2);

    m.def("min", &min, "A function that min two numbers");
}