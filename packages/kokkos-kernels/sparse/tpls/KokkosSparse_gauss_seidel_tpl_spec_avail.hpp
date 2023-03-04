//@HEADER
// ************************************************************************
//
//                        Kokkos v. 4.0
//       Copyright (2022) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Part of Kokkos, under the Apache License v2.0 with LLVM Exceptions.
// See https://kokkos.org/LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//@HEADER

#ifndef KOKKOSPARSE_GAUSS_SEIDEL_TPL_SPEC_AVAIL_HPP_
#define KOKKOSPARSE_GAUSS_SEIDEL_TPL_SPEC_AVAIL_HPP_

namespace KokkosSparse {
namespace Impl {
// Specialization struct which defines whether a specialization exists
template <class KernelHandle, class a_size_view_t_, class a_lno_view_t>
struct gauss_seidel_symbolic_tpl_spec_avail {
  enum : bool { value = false };
};

// Specialization struct which defines whether a specialization exists
template <class KernelHandle, class a_size_view_t_, class a_lno_view_t,
          class a_scalar_view_t>
struct gauss_seidel_numeric_tpl_spec_avail {
  enum : bool { value = false };
};

// Specialization struct which defines whether a specialization exists
template <class KernelHandle, class a_size_view_t_, class a_lno_view_t,
          class a_scalar_view_t, class x_scalar_view_t, class y_scalar_view_t>
struct gauss_seidel_apply_tpl_spec_avail {
  enum : bool { value = false };
};

}  // namespace Impl
}  // namespace KokkosSparse

#endif
