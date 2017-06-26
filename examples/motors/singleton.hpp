#ifndef SINGLETON_HPP
#define SINGLETON_HPP

//! \class Singleton singleton.hpp <base/singleton.hpp>
//! \brief Interface for classes that should have only one instance.
//! \param _BASE : The class that should have only one instance.
template<typename _BASE>
class Singleton {
protected:
  //! \brief Protected default constructor, to avoid instanciation.
  inline Singleton(void) {
  }

  //! \brief Protected copy constructor, to avoid copy construction.
  inline Singleton(const Singleton&) {
  }

public:
  //! \brief Access to the single instance of the class.
  //! \return A reference to the instance.
  static inline _BASE& instance(void) {
    static _BASE inst;
    return inst;
  }
};

#endif//SINGLETON_HPP
