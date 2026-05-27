#ifndef CPPAD_CG_CPPADCG_EIGEN_INCLUDED
#define CPPAD_CG_CPPADCG_EIGEN_INCLUDED
/* --------------------------------------------------------------------------
 *  CppADCodeGen: C++ Algorithmic Differentiation with Source Code Generation:
 *    Copyright (C) 2017 Ciengis
 *
 *  CppADCodeGen is distributed under multiple licenses:
 *
 *   - Eclipse Public License Version 1.0 (EPL1), and
 *   - GNU General Public License Version 3 (GPL3).
 *
 *  EPL1 terms and conditions can be found in the file "epl-v10.txt", while
 *  terms and conditions for the GPL3 can be found in the file "gpl3.txt".
 * ----------------------------------------------------------------------------
 * Author: Joao Leal
 */

# include <cppad/cg.hpp>
# include <Eigen/Dense>

/**
 * Enable Use of Eigen Linear Algebra Package with CppADCodeGen
 */
namespace Eigen {

/**
 * NumTraits specialization for the eigen library (3.3).
 * This is required so that the type CG<Base> works properly with eigen.
 * See Eigen/src/Core/NumTraits.h
 */
template<typename Base>
struct NumTraits<CppAD::cg::CG<Base> > {
    // the real part of an CG<Base> value
    using Real = CppAD::cg::CG<Base> ;
    // type for CG<Base> operations producing non-integer values
    using NonInteger = CppAD::cg::CG<Base> ;
    // type for nested value inside an CG<Base> expression tree
    using Nested = CppAD::cg::CG<Base>;
    // type for numeric literals such as "2" or "0.5"
    using Literal = CppAD::cg::CG<Base>;

    enum {
        // does not support complex Base types
        IsComplex             = 0 ,
        // does not support integer Base types
        IsInteger             = 0 ,
        // only support signed Base types
        IsSigned              = 1 ,
        // must initialize an CG<Base> object
        RequireInitialization = 1 ,
        // computational cost of the corresponding operations
        ReadCost              = 1 ,
        AddCost               = 2 ,
        MulCost               = 2
    };

    /**
     * machine epsilon with type of real part of x
     * (use assumption that Base is not complex)
     */
    static CppAD::cg::CG<Base>  epsilon() {
        return CppAD::numeric_limits<CppAD::cg::CG<Base> >::epsilon();
    }

    /**
     * relaxed version of machine epsilon for comparison of different
     * operations that should result in the same value*
     */
    static CppAD::cg::CG<Base> dummy_precision() {
        return 100. * CppAD::numeric_limits<CppAD::cg::CG<Base> >::epsilon();
    }

    /**
     * minimum normalized positive value
     */
    static CppAD::cg::CG<Base> lowest() {
        return CppAD::numeric_limits<CppAD::cg::CG<Base> >::min();
    }

    /**
     * maximum finite value
     */
    static CppAD::cg::CG<Base> highest() {
        return CppAD::numeric_limits<CppAD::cg::CG<Base> >::max();
    }

    /**
     * the number of decimal digits that can be represented without change
     */
    static int digits10() {
        return CppAD::numeric_limits<CppAD::cg::CG<Base> >::digits10;
    }

    /**
     * the number of radix digits
     */
    static int digits() {
      return std::numeric_limits<Base>::digits;
    }

    /**
     * the number of decimal digits required to uniquely represent all distinct values of the type
     */
    static int max_digits10() {
      return std::numeric_limits<Base>::max_digits10;
    }

    /**
     * the lowest possible value, such that the radix raised to the power exponent-1 is a normalized floating-point number
     */
    static int min_exponent() {
      return std::numeric_limits<Base>::min_exponent;
    }

    /**
     * the highest possible value, such that the radix raised to the power exponent-1 is a normalized floating-point number
     */
    static int max_exponent() {
      return std::numeric_limits<Base>::max_exponent;
    }

    /**
     * representation of positive infinity
     */
    static CppAD::cg::CG<Base> infinity() {
      return CppAD::numeric_limits<CppAD::cg::CG<Base> >::infinity();
    }

    /**
     * a non-signaling "not-a-number"
     */
    static CppAD::cg::CG<Base> quiet_NaN() {
      return CppAD::numeric_limits<CppAD::cg::CG<Base> >::quiet_NaN();
    }
};

/**
 * NumTraits specialization for the eigen library (3.3).
 * This is required so that the type AD<CG<Base> > works properly with eigen.
 * See Eigen/src/Core/NumTraits.h
 */
template <typename Base>
struct NumTraits<CppAD::AD<CppAD::cg::CG<Base> > > {
    using CGBase = CppAD::cg::CG<Base>;
    // the real part of an AD<CGBase> value
    using Real = CppAD::AD<CGBase>;
    // type for AD<CGBase> operations producing non-integer values
    using NonInteger = CppAD::AD<CGBase>;
    // type for nested value inside an AD<CGBase> expression tree
    using Nested = CppAD::AD<CGBase>;
    // type for numeric literals such as "2" or "0.5"
    using Literal = CppAD::AD<CGBase>;

    enum {
        // does not support complex Base types
        IsComplex             = 0 ,
        // does not support integer Base types
        IsInteger             = 0 ,
        // only support signed Base types
        IsSigned              = 1 ,
        // must initialize an AD<CGBase> object
        RequireInitialization = 1 ,
        // computational cost of the corresponding operations
        ReadCost              = 1 ,
        AddCost               = 2 ,
        MulCost               = 2
    };

    /**
     * machine epsilon with type of real part of x
     * (use assumption that Base is not complex)
     */
    static CppAD::AD<CGBase>  epsilon() {
        return CppAD::numeric_limits<CppAD::AD<CGBase> >::epsilon();
    }

    /**
     * relaxed version of machine epsilon for comparison of different
     * operations that should result in the same value*
     */
    static CppAD::AD<CGBase> dummy_precision() {
        return 100. * CppAD::numeric_limits<CppAD::AD<CGBase> >::epsilon();
    }

    /**
     * minimum normalized positive value
     */
    static CppAD::AD<CGBase> lowest() {
        return CppAD::numeric_limits<CppAD::AD<CGBase> >::min();
    }

    /**
     * maximum finite value
     */
    static CppAD::AD<CGBase> highest() {
        return CppAD::numeric_limits<CppAD::AD<CGBase> >::max();
    }

    /**
     * the number of decimal digits that can be represented without change
     */
    static int digits10() {
        return CppAD::numeric_limits<CGBase>::digits10;
    }

    /**
     * the number of radix digits
     */
    static int digits() {
      return std::numeric_limits<Base>::digits;
    }

    /**
     * the number of decimal digits required to uniquely represent all distinct values of the type
     */
    static int max_digits10() {
      return std::numeric_limits<Base>::max_digits10;
    }

    /**
     * the lowest possible value, such that the radix raised to the power exponent-1 is a normalized floating-point number
     */
    static int min_exponent() {
      return std::numeric_limits<Base>::min_exponent;
    }

    /**
     * the highest possible value, such that the radix raised to the power exponent-1 is a normalized floating-point number
     */
    static int max_exponent() {
      return std::numeric_limits<Base>::max_exponent;
    }

    /**
     * representation of positive infinity
     */
    static CppAD::AD<CGBase> infinity() {
      return CppAD::numeric_limits<CppAD::AD<CGBase>>::infinity();
    }

    /**
     * a non-signaling "not-a-number"
     */
    static CppAD::AD<CGBase> quiet_NaN() {
      return CppAD::numeric_limits<CppAD::AD<CGBase>>::quiet_NaN();
    }

};

#if EIGEN_VERSION_AT_LEAST(3,2,93)

/**
 * Determines that the given binary operation of two numeric types involving
 * an AD<CG<Base> > is allowed and what the scalar return type is
 */
template<typename Base, typename BinOp>
struct ScalarBinaryOpTraits<CppAD::AD<CppAD::cg::CG<Base> >, Base, BinOp> {
    using ReturnType = CppAD::AD<CppAD::cg::CG<Base> >;
};

template<typename Base, typename BinOp>
struct ScalarBinaryOpTraits<Base, CppAD::AD<CppAD::cg::CG<Base> >, BinOp> {
    using ReturnType = CppAD::AD<CppAD::cg::CG<Base> >;
};

template<typename Base, typename BinOp>
struct ScalarBinaryOpTraits<CppAD::AD<CppAD::cg::CG<Base> >, CppAD::cg::CG<Base>, BinOp> {
    using ReturnType = CppAD::AD<CppAD::cg::CG<Base> >;
};

template<typename Base, typename BinOp>
struct ScalarBinaryOpTraits<CppAD::cg::CG<Base>, CppAD::AD<CppAD::cg::CG<Base> >, BinOp> {
    using ReturnType = CppAD::AD<CppAD::cg::CG<Base> >;
};


/**
 * Determines that the given binary operation of two numeric types involving
 * an CG<Base> is allowed and what the scalar return type is
 */
template<typename Base, typename BinOp>
struct ScalarBinaryOpTraits<CppAD::cg::CG<Base>, Base, BinOp> {
    using ReturnType = CppAD::cg::CG<Base>;
};

template<typename Base, typename BinOp>
struct ScalarBinaryOpTraits<Base, CppAD::cg::CG<Base>, BinOp> {
    using ReturnType = CppAD::cg::CG<Base>;
};

#endif // #ifdef EIGEN_VERSION_AT_LEAST(3,2,93)

} // namespace Eigen

namespace CppAD {
namespace cg {

/**
 * Additional functions required by Eigen for AD<CG<Base> >
 */

// functions that return references
template <class Base>
const CppAD::AD<CppAD::cg::CG<Base> >& conj(const CppAD::AD<CppAD::cg::CG<Base> >& x) {
    return x;
}

template <class Base>
const CppAD::AD<CppAD::cg::CG<Base> >& real(const CppAD::AD<CppAD::cg::CG<Base> >& x) {
    return x;
}

// functions that return values (note abs is defined by cppadcg.hpp)
template <class Base>
CppAD::AD<CppAD::cg::CG<Base> > imag(const CppAD::AD<CppAD::cg::CG<Base> >& x) {
    return CppAD::AD<CppAD::cg::CG<Base> >(0.);
}

template <class Base>
CppAD::AD<CppAD::cg::CG<Base> > abs2(const CppAD::AD<CppAD::cg::CG<Base> >& x) {
    return x * x;
}

/**
 * Additional functions required by Eigen for CG<Base>
 */

// functions that return references
template <class Base>
const CppAD::cg::CG<Base>& conj(const CppAD::cg::CG<Base>& x) {
    return x;
}

template <class Base>
const CppAD::cg::CG<Base>& real(const CppAD::cg::CG<Base>& x) {
    return x;
}

// functions that return values (note abs is defined by cppadcg.hpp)
template <class Base>
CppAD::cg::CG<Base> imag(const CppAD::cg::CG<Base>& x) {
    return CppAD::cg::CG<Base>(0.);
}

template <class Base>
CppAD::cg::CG<Base> abs2(const CppAD::cg::CG<Base>& x) {
    return x * x;
}

}
}

# endif
