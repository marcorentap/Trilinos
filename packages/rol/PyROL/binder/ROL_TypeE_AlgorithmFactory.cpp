#include <ROL_TypeE_AlgorithmFactory.hpp>
#include <iterator>
#include <memory>
#include <string>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <Teuchos_RCP.hpp>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, Teuchos::RCP<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(Teuchos::RCP<void>)
#endif

void bind_ROL_TypeE_AlgorithmFactory(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// ROL::TypeE::EAlgorithmE file:ROL_TypeE_AlgorithmFactory.hpp line:59
	pybind11::enum_<ROL::TypeE::EAlgorithmE>(M("ROL::TypeE"), "EAlgorithmE", pybind11::arithmetic(), "Enumeration of equality constrained algorithm types.", pybind11::module_local())
		.value("ALGORITHM_E_AUGMENTEDLAGRANGIAN", ROL::TypeE::ALGORITHM_E_AUGMENTEDLAGRANGIAN)
		.value("ALGORITHM_E_FLETCHER", ROL::TypeE::ALGORITHM_E_FLETCHER)
		.value("ALGORITHM_E_COMPOSITESTEP", ROL::TypeE::ALGORITHM_E_COMPOSITESTEP)
		.value("ALGORITHM_E_STABILIZEDLCL", ROL::TypeE::ALGORITHM_E_STABILIZEDLCL)
		.value("ALGORITHM_E_LAST", ROL::TypeE::ALGORITHM_E_LAST)
		.export_values();

;

	// ROL::TypeE::EAlgorithmEToString(enum ROL::TypeE::EAlgorithmE) file:ROL_TypeE_AlgorithmFactory.hpp line:67
	M("ROL::TypeE").def("EAlgorithmEToString", (std::string (*)(enum ROL::TypeE::EAlgorithmE)) &ROL::TypeE::EAlgorithmEToString, "C++: ROL::TypeE::EAlgorithmEToString(enum ROL::TypeE::EAlgorithmE) --> std::string", pybind11::arg("alg"));

	// ROL::TypeE::isValidAlgorithmE(enum ROL::TypeE::EAlgorithmE) file:ROL_TypeE_AlgorithmFactory.hpp line:85
	M("ROL::TypeE").def("isValidAlgorithmE", (int (*)(enum ROL::TypeE::EAlgorithmE)) &ROL::TypeE::isValidAlgorithmE, "Verifies validity of a AlgorithmE enum.\n\n    \n  [in]  - enum of the AlgorithmE\n    \n\n 1 if the argument is a valid AlgorithmE; 0 otherwise.\n\nC++: ROL::TypeE::isValidAlgorithmE(enum ROL::TypeE::EAlgorithmE) --> int", pybind11::arg("alg"));

	// ROL::TypeE::StringToEAlgorithmE(std::string) file:ROL_TypeE_AlgorithmFactory.hpp line:114
	M("ROL::TypeE").def("StringToEAlgorithmE", (enum ROL::TypeE::EAlgorithmE (*)(std::string)) &ROL::TypeE::StringToEAlgorithmE, "C++: ROL::TypeE::StringToEAlgorithmE(std::string) --> enum ROL::TypeE::EAlgorithmE", pybind11::arg("s"));

}
