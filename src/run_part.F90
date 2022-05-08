module PyPartMC_run_part

use iso_c_binding
use pmc_run_part

implicit none

type, bind(C) :: run_part_opt_c
   real(kind=dp) :: t_max
   real(kind=dp) :: t_output
end type run_part_opt_c

contains

subroutine py_run_part(arg_run_part_opt) bind(C)

   type(scenario_t) :: scenario
   type(env_state_t) :: env_state
   type(aero_data_t) :: aero_data
   type(aero_state_t) :: aero_state
   type(gas_data_t) :: gas_data
   type(gas_state_t) :: gas_state

   type(run_part_opt_c) :: arg_run_part_opt
   type(run_part_opt_t) :: run_part_opt

   call run_part(scenario, env_state, aero_data, aero_state, gas_data, gas_state, run_part_opt)

end subroutine

end module