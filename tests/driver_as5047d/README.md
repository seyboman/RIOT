# About
This is a manual test application for the AS5047D driver.

# Usage
This test application will initialize the AS5047D sensor with the configuration
as specified in the default `as5047d_params.h` file.

If you want to use this test application with different parameters, you can
simply override the default AS5047D_PARAMS.

After initialization, the sensor reads the pulse counter values every second and
prints them to STDOUT.
