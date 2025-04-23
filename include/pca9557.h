/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2021 <ESPRESSIF SYSTEMS (SHANGHAI) CO., LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _PCA9557_H
#define _PCA9557_H

#ifdef __cplusplus
extern "C" {
#endif

#include "driver/gpio.h"

typedef enum {
    PCA9557_GPIO_NUM_0 = BIT(0),
    PCA9557_GPIO_NUM_1 = BIT(1),
    PCA9557_GPIO_NUM_2 = BIT(2),
    PCA9557_GPIO_NUM_3 = BIT(3),
    PCA9557_GPIO_NUM_4 = BIT(4),
    PCA9557_GPIO_NUM_5 = BIT(5),
    PCA9557_GPIO_NUM_6 = BIT(6),
    PCA9557_GPIO_NUM_7 = BIT(7),
    PCA9557_GPIO_NUM_MAX
} esp_pca9557_gpio_num_t;

typedef enum {
    PCA9557_IO_LOW,
    PCA9557_IO_HIGH,
    PCA9557_LEVEL_ERROR
} esp_pca9557_io_level_t;

typedef enum {
    PCA9557_IO_RETAINED,
    PCA9557_IO_INVERTED
} esp_pca9557_io_polarity_t;

typedef enum {
    PCA9557_IO_OUTPUT,
    PCA9557_IO_INPUT
} esp_pca9557_io_config_t;

typedef struct {
    gpio_num_t i2c_sda;
    gpio_num_t i2c_scl;
    gpio_num_t interrupt_output;
} esp_pca9557_config_t;

/*
 * @brief Initialize PCA9557 chip
 *
 * @param codec_cfg  configuration of PCA9557
 *
 * @return
 *      - ESP_OK
 *      - ESP_FAIL
 */
esp_err_t pca9557_init(esp_pca9557_config_t *cfg);

/**
 * @brief Deinitialize PCA9557 chip
 *
 * @return
 *     - ESP_OK
 *     - ESP_FAIL
 */
esp_err_t pca9557_deinit(void);

/*
 * @brief Get PCA9557 input level
 *
 * @param gpio_num  GPIO of PCA9557
 *
 * @return
 *      - esp_pca9557_io_level_t
 */
esp_pca9557_io_level_t pca9557_get_input_state(esp_pca9557_gpio_num_t gpio_num);

/*
 * @brief Get PCA95xian39 output level
 *
 * @param gpio_num  GPIO of PCA9557
 *
 * @return
 *      - esp_pca9557_io_level_t
 */
esp_pca9557_io_level_t pca9557_get_output_state(esp_pca9557_gpio_num_t gpio_num);

/*
 * @brief Get PCA9557 output state
 *
 * @param gpio_num  GPIO of PCA9557
 *
 * @return
 *      - esp_pca9557_io_level_t
 */
esp_err_t pca9557_set_output_state(esp_pca9557_gpio_num_t gpio_num, esp_pca9557_io_level_t level);

/*
 * @brief Set PCA9557 polarity
 *
 * @param gpio_num  GPIO of PCA9557
 *        polarity  polarity
 *
 * @return
 *      - ESP_OK
 *      - ESP_FAIL
 */
esp_err_t pca9557_set_polarity_inversion(esp_pca9557_gpio_num_t gpio_num, esp_pca9557_io_polarity_t polarity);

/*
 * @brief Get PCA9557 output level
 *
 * @param gpio_num  GPIO of PCA9557
 *
 * @return
 *      - esp_pca9557_io_level_t
 */
esp_pca9557_io_config_t pca9557_get_io_config(esp_pca9557_gpio_num_t gpio_num);

/*
 * @brief Set PCA9557 io config
 *
 * @param gpio_num  GPIO of PCA9557
 *        io_config  io config
 *
 * @return
 *      - ESP_OK
 *      - ESP_FAIL
 */
esp_err_t pca9557_set_io_config(esp_pca9557_gpio_num_t gpio_num, esp_pca9557_io_config_t io_config);

/**
 * @brief Print all PCA9557 registers
 *
 * @return
 *     - void
 */
void pca9557_read_all();

#ifdef __cplusplus
}
#endif

#endif
