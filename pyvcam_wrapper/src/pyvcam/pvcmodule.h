#ifndef PVC_MODULE_H_
#define PVC_MODULE_H_

// System
#include <Python.h>
#include <string>
#include <vector>

// PVCAM
#include <master.h>
#include <pvcam.h>

/*
 *Global Variables
 */
char g_msg[ERROR_MSG_LEN]; // Global Error Message Variable.
bool DEBUG = false;
extern FRAME_INFO *g_pFrameInfo;
uns16 *frameAddress2;
int16 hcam2;
/*
 * Common data types
 */
// Name-Value Pair type - an item in enumeration type
typedef struct NVP
{
    int32 value;
    std::string name;
} NVP;
// Name-Value Pair Container type - an enumeration type
typedef std::vector<NVP> NVPC;

/* Each camera has one or more ports, this structure holds information
 * with port descriptions. Each camera port has one or more speeds
 * (readout frequencies). On most EM cameras there are two ports - one
 * EM and one non-EM port with one or two speeds per port.
 * On non-EM camera there is usually one port only with multiple speeds. */
typedef struct READOUT_OPTION
{
    NVP port;
    int16 speedIndex;
    float reaoutFrequency;
    int16 bitDepth;
    std::vector<int16> gains;
}READOUT_OPTION;

/*
 * Documentation Strings
 */
static char module_docstring[] =
"This module provides an interface for various PVCAM functions.";
static char get_pvcam_version_docstring[] =
"Returns the current version of PVCAM.";
static char get_cam_fw_version_docstring[] =
"Gets the cameras firmware version";
static char get_cam_total_docstring[] =
"Returns the number of available cameras currently connected to the system.";
static char init_pvcam_docstring[] =
"Initializes PVCAM library.";
static char uninit_pvcam_docstring[] =
"Uninitializes PVCAM library.";
static char get_cam_name_docstring[] =
"Return the name of a camera given its handle/camera number.";
static char open_camera_docstring[] =
"Opens a specified camera.";
static char close_camera_docstring[] =
"Closes a specified camera.";
static char get_param_docstring[] =
"Returns the value of a camera associated with the specified parameter.";
static char set_param_docstring[] =
"Sets a specified parameter to a specified value.";
static char check_param_docstring[] =
"Checks if a specified setting of a camera is available.";
static char get_enum_param_docstring[] =
"Returns the enumerated value of the specified parameter at `index`.";
static char get_frame_docstring[] =
"Returns the a numpy array of pixel data acquired from a single snap.";
static char start_live_docstring[] =
"Starts live mode aquisiton";
static char start_live_cb_docstring[] =
"Starts live mode aquisiton with callbacks";
static char get_live_frame_docstring[] =
"Gets a frame during life mode";
static char get_live_frame_cb_docstring[] =
"Gets a frame during live mode with callbacks and the fps";
static char stop_live_docstring[] =
"Stops live mode";
static char set_exp_modes_docstring[] =
"Sets a camera's exposure mode or expose out mode.";
static char read_enum_docstring[] =
"Returns a list of all key-value pairs of a given enum type.";
static char reset_pp_docstring[] =
"Resets all post-processing modules to their default values.";
static char my_set_callback_docstring[] =
"Initializes a python callback";

/*
 * Functions
 */
void set_g_msg(void);
int is_avail(int16 hcam, uns32 param_id);
static PyObject *pvc_get_pvcam_version(PyObject *self, PyObject* args);
static PyObject *pvc_get_cam_fw_version(PyObject *self, PyObject* args);
static PyObject *pvc_init_pvcam(PyObject *self, PyObject* args);
static PyObject *pvc_uninit_pvcam(PyObject *self, PyObject* args);
static PyObject *pvc_get_cam_total(PyObject *self, PyObject* args);
static PyObject *pvc_get_cam_name(PyObject *self, PyObject *args);
static PyObject *pvc_open_camera(PyObject *self, PyObject *args);
static PyObject *pvc_close_camera(PyObject *self, PyObject *args);
static PyObject *pvc_get_param(PyObject *self, PyObject *args);
static PyObject *pvc_set_param(PyObject *self, PyObject *args);
static PyObject *pvc_check_param(PyObject *self, PyObject *args);
static PyObject *pvc_get_frame(PyObject *self, PyObject *args);
static PyObject *pvc_start_live(PyObject *self, PyObject *args);
static PyObject *pvc_get_live_frame(PyObject *self, PyObject *args);
static PyObject *pvc_start_live_cb(PyObject *self, PyObject *args);
static PyObject *pvc_get_live_frame_cb(PyObject *self, PyObject *args);
static PyObject *pvc_stop_live(PyObject *self, PyObject *args);
static PyObject *pvc_set_exp_modes(PyObject *self, PyObject *args);
int valid_enum_param(int16 hcam, uns32 param_id, int32 selected_val);
static PyObject *pvc_reset_pp(PyObject *self, PyObject *args);
static PyObject *pvc_my_set_callback(PyObject *self, PyObject *args);

#endif // PVC_MODULE_H_
