#include <pybind11/stl.h>

#include "record.hpp"
#include "calculate.hpp"

namespace py = pybind11;
PYBIND11_MODULE(logistic, m)
{
    m.doc() = "calculate bifurcation of logistic map";

    py::class_<Record>(m, "record")
        .def(py::init<int>())
        .def_readwrite("x_list", &Record::x_list)
        .def_readwrite("mu_list", &Record::mu_list);

    m.def("logistic", &logistic);
}