/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High Performance Interior Point Method.                                                *
* Copyright (C) 2017 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* HPIPM is free software; you can redistribute it and/or                                          *
* modify it under the terms of the GNU Lesser General Public                                      *
* License as published by the Free Software Foundation; either                                    *
* version 2.1 of the License, or (at your option) any later version.                              *
*                                                                                                 *
* HPIPM is distributed in the hope that it will be useful,                                        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *
* See the GNU Lesser General Public License for more details.                                     *
*                                                                                                 *
* You should have received a copy of the GNU Lesser General Public                                *
* License along with HPIPM; if not, write to the Free Software                                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/



#include <blasfeo_target.h>
#include <blasfeo_common.h>

#ifdef __cplusplus
extern "C" {
#endif


struct d_tree_ocp_qp_ipm_arg
	{
	double mu0; // initial value for duality measure
	double alpha_min; // exit cond on step length
	double res_g_max; // exit cond on inf norm of residuals
	double res_b_max; // exit cond on inf norm of residuals
	double res_d_max; // exit cond on inf norm of residuals
	double res_m_max; // exit cond on inf norm of residuals
	int iter_max; // exit cond in iter number
	int stat_max; // iterations saved in stat
	int pred_corr; // use Mehrotra's predictor-corrector IPM algirthm
	int cond_pred_corr; // conditional Mehrotra's predictor-corrector
	int warm_start; // 0 no warm start, 1 warm start primal sol
	int memsize;
	};



struct d_tree_ocp_qp_ipm_workspace
	{
	struct d_core_qp_ipm_workspace *core_workspace;
	struct blasfeo_dvec *dux;
	struct blasfeo_dvec *dpi;
	struct blasfeo_dvec *dt;
	struct blasfeo_dvec *res_g; // q-residuals
	struct blasfeo_dvec *res_b; // b-residuals
	struct blasfeo_dvec *res_d; // d-residuals
	struct blasfeo_dvec *res_m; // m-residuals
	struct blasfeo_dvec *Gamma; // hessian update
	struct blasfeo_dvec *gamma; // hessian update
	struct blasfeo_dvec *tmp_nxM; // work space of size nxM
	struct blasfeo_dvec *tmp_nbgM; // work space of size nbgM
	struct blasfeo_dvec *tmp_nsM; // work space of size nsM
	struct blasfeo_dvec *Pb; // Pb
	struct blasfeo_dvec *Zs_inv;
	struct blasfeo_dmat *L;
	struct blasfeo_dmat *AL;
	double *stat; // convergence statistics
	double qp_res[4]; // infinity norm of residuals
	double mu0; // mu0
	double res_mu; // mu-residual
	int iter; // iteration number
	int stat_max; // iterations saved in stat
	int warm_start; // 0 no warm start, 1 warm start primal sol
	int memsize;
	};



//
int d_memsize_tree_ocp_qp_ipm_arg(struct d_tree_ocp_qp *qp);
//
void d_create_tree_ocp_qp_ipm_arg(struct d_tree_ocp_qp *qp, struct d_tree_ocp_qp_ipm_arg *arg, void *mem);
//
void d_set_default_tree_ocp_qp_ipm_arg(struct d_tree_ocp_qp_ipm_arg *arg);

//
int d_memsize_tree_ocp_qp_ipm(struct d_tree_ocp_qp *qp, struct d_tree_ocp_qp_ipm_arg *arg);
//
void d_create_tree_ocp_qp_ipm(struct d_tree_ocp_qp *qp, struct d_tree_ocp_qp_ipm_arg *arg, struct d_tree_ocp_qp_ipm_workspace *ws, void *mem);
//
int d_solve_tree_ocp_qp_ipm(struct d_tree_ocp_qp *qp, struct d_tree_ocp_qp_sol *qp_sol, struct d_tree_ocp_qp_ipm_arg *arg, struct d_tree_ocp_qp_ipm_workspace *ws);

#ifdef __cplusplus
} /* extern "C" */
#endif
