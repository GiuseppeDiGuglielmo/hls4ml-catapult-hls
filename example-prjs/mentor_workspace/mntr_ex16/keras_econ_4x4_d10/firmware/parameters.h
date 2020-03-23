#ifndef PARAMETERS_H_
#define PARAMETERS_H_

/* #include <complex> */
/* #include "ap_int.h" */
/* #include "ap_fixed.h" */
/* #include "nnet_utils/nnet_dense.h" */
#include "nnet_utils/nnet_dense_large.h"
/* #include "nnet_utils/nnet_dense_compressed.h" */
/* #include "nnet_utils/nnet_conv.h" */
#include "nnet_utils/nnet_conv2d.h"
#include "nnet_utils/nnet_activation.h"
/* #include "nnet_utils/nnet_common.h" */
/* #include "nnet_utils/nnet_batchnorm.h" */
/* #include "nnet_utils/nnet_pooling.h" */
/* #include "nnet_utils/nnet_merge.h" */
/* #include "nnet_utils/nnet_helpers.h" */

//hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 4
#define N_INPUT_2_1 4
#define N_INPUT_3_1 3
#define OUT_HEIGHT_2 4
#define OUT_WIDTH_2 4
#define N_FILT_2 8
#define N_LAYER_4 10

//hls-fpga-machine-learning insert layer-precision
#ifdef __AC_FLOAT__
typedef ac_float<4,1,3> model_default_t;
typedef ac_float<4,1,3> input_t;
typedef ac_float<4,1,3> layer2_t;
typedef ac_float<4,1,3> layer3_t;
typedef ac_float<4,1,3> layer4_t;
typedef ac_float<4,1,3> result_t;
#else
typedef ap_fixed<8,1> model_default_t;
typedef ap_fixed<8,2> input_t;
typedef ap_fixed<8,2> layer2_t;
typedef ap_fixed<8,2> layer3_t;
typedef ap_fixed<8,2> layer4_t;
typedef ap_fixed<8,2> result_t;
#endif

//hls-fpga-machine-learning insert layer-config
struct config2 : nnet::conv2d_config {
    static const unsigned pad_top = 1;
    static const unsigned pad_bottom = 1;
    static const unsigned pad_left = 1;
    static const unsigned pad_right = 1;
    static const unsigned in_height = N_INPUT_1_1;
    static const unsigned in_width = N_INPUT_2_1;
    static const unsigned n_chan = N_INPUT_3_1;
    static const unsigned filt_height = 3;
    static const unsigned filt_width = 3;
    static const unsigned n_filt = N_FILT_2;
    static const unsigned stride_height = 1;
    static const unsigned stride_width = 1;
    static const unsigned out_height = OUT_HEIGHT_2;
    static const unsigned out_width = OUT_WIDTH_2;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const bool store_weights_in_bram = false;
#ifdef __AC_FLOAT__
    typedef ac_float<4,1,3> accum_t;
#else
    typedef ap_fixed<8,2> accum_t;
#endif
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
};

struct relu_config3 : nnet::activ_config {
    static const unsigned n_in = OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

struct config4 : nnet::dense_config {
    static const unsigned n_in = OUT_HEIGHT_2*OUT_WIDTH_2*N_FILT_2;
    static const unsigned n_out = N_LAYER_4;
    static const unsigned io_type = nnet::io_parallel;
    static const unsigned reuse_factor = 1;
    static const unsigned n_zeros = 0;
    static const unsigned n_nonzeros = 1280;
    static const bool store_weights_in_bram = false;
#ifdef __AC_FLOAT__
    typedef ac_float<4,1,3> accum_t;
#else
    typedef ap_fixed<8,2> accum_t;
#endif
    typedef model_default_t bias_t;
    typedef model_default_t weight_t;
    typedef ap_uint<1> index_t;
};

struct relu_config5 : nnet::activ_config {
    static const unsigned n_in = N_LAYER_4;
    static const unsigned table_size = 1024;
    static const unsigned io_type = nnet::io_parallel;
};

#endif