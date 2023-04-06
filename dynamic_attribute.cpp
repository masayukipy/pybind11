#include <pybind11/pybind11.h>

namespace py = pybind11;

class Pet {
    public:
        Pet(){ }
        std::string name="Molly";
};

PYBIND11_MODULE(dynamicAttribute, m) {
    py::class_<Pet>(m, "Pet", py::dynamic_attr())
        .def(py::init<>())
        .def_readwrite("name", &Pet::name);
}
