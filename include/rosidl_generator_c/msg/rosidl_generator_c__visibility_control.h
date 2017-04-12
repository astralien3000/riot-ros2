// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define ROSIDL_GENERATOR_C__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_rosidl_generator_c __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_rosidl_generator_c __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_rosidl_generator_c __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_rosidl_generator_c __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_rosidl_generator_c
    #define ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c ROSIDL_GENERATOR_C_EXPORT_rosidl_generator_c
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c ROSIDL_GENERATOR_C_IMPORT_rosidl_generator_c
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_rosidl_generator_c __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_rosidl_generator_c
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
