/*##################################################################################################
# This file is a part of PyPartMC licensed under the GNU General Public License v3 (LICENSE file)  #
# Copyright (C) 2022 University of Illinois Urbana-Champaign                                       #
# Author: Sylwester Arabas                                                                         #
##################################################################################################*/

#pragma once
#include <string>
#include "pybind11_json/pybind11_json.hpp"
#include "nlohmann/json.hpp"
#include "gimmicks.hpp"

extern "C" void f_gas_state_ctor(void *ptr, const int *n);
extern "C" void f_gas_state_dtor(void *ptr);
extern "C" void f_gas_state_set_item(const void *ptr, const int *idx, const double *val);
extern "C" void f_gas_state_get_item(const void *ptr, const int *idx, double *val);
extern "C" void f_gas_state_len(const void *ptr, int *len);
extern "C" void f_gas_state_to_json(const void *ptr);
extern "C" void f_gas_state_from_json(const void *ptr);

struct GasState {
    // TODO: common base class?
    void *ptr;
    GasState(const GasState &obj) = delete;
    GasState& operator= (const GasState&) = delete;

    GasState(const nlohmann::json &json) {
        gimmick_ptr() = std::make_unique<InputGimmick>(json);

        const int n = json.empty() ? 0 : gimmick_ptr()->find("gas_mixing_ratio")->size();
        f_gas_state_ctor(&this->ptr, &n);
        if (n != 0) f_gas_state_from_json(&this->ptr);

        gimmick_ptr().reset(); // TODO: guard
    }

    ~GasState() {
        f_gas_state_dtor(&this->ptr);
    }

    static void set_item(const GasState &self, const int &idx, const double &val) {
        if (idx < 0 || idx >= (int)__len__(self))
            throw std::out_of_range("TODO");
        f_gas_state_set_item(&self.ptr, &idx, &val);
    }

    //static void set_items(const GasState &self, const py::slice &idx, const py::array_t<double> &vals) {
    //    throw std::runtime_error("TODO");
    //}

    static double get_item(const GasState &self, const int &idx) {
        if (idx < 0 || idx >= (int)__len__(self))
            throw std::out_of_range("TODO");
        double value;
        f_gas_state_get_item(&self.ptr, &idx, &value);
        return value;
    }

    //static py::array_t<double> get_items(const GasState &self, const py::slice &idx) {
    //    throw std::runtime_error("TODO");
        //f_get_item(self.ptr, &arr);
        //return py::array_t<double>();
    //}

    static std::string __str__(const GasState &self) {
        gimmick_ptr() = std::make_unique<OutputGimmick>(); // TODO: guard

        f_gas_state_to_json(&self.ptr);
        auto str = gimmick_ptr()->str();

        gimmick_ptr().reset(); // TODO: guard
        return str;
    }

    static std::size_t __len__(const GasState &self) {
        int len;
        f_gas_state_len(&self.ptr, &len);
        return len;
    }
};
