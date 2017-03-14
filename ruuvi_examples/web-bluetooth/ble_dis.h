/* This file was generated by plugin 'Nordic Semiconductor nRF5x v.1.2.2' (BDS version 1.1.3135.0) */

#ifndef BLE_DIS_H__
#define BLE_DIS_H__

#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"
#include "app_util_bds.h"



/**@brief Device Information event type. */
typedef enum
{ 
    BLE_DIS_MANUFACTURER_NAME_STRING_EVT_NOTIFICATION_ENABLED,  /**< Manufacturer Name String value notification enabled event. */
    BLE_DIS_MANUFACTURER_NAME_STRING_EVT_NOTIFICATION_DISABLED, /**< Manufacturer Name String value notification disabled event. */
    BLE_DIS_MODEL_NUMBER_STRING_EVT_NOTIFICATION_ENABLED,  /**< Model Number String value notification enabled event. */
    BLE_DIS_MODEL_NUMBER_STRING_EVT_NOTIFICATION_DISABLED, /**< Model Number String value notification disabled event. */
    BLE_DIS_SERIAL_NUMBER_STRING_EVT_NOTIFICATION_ENABLED,  /**< Serial Number String value notification enabled event. */
    BLE_DIS_SERIAL_NUMBER_STRING_EVT_NOTIFICATION_DISABLED, /**< Serial Number String value notification disabled event. */
    BLE_DIS_HARDWARE_REVISION_STRING_EVT_NOTIFICATION_ENABLED,  /**< Hardware Revision String value notification enabled event. */
    BLE_DIS_HARDWARE_REVISION_STRING_EVT_NOTIFICATION_DISABLED, /**< Hardware Revision String value notification disabled event. */
    BLE_DIS_FIRMWARE_REVISION_STRING_EVT_NOTIFICATION_ENABLED,  /**< Firmware Revision String value notification enabled event. */
    BLE_DIS_FIRMWARE_REVISION_STRING_EVT_NOTIFICATION_DISABLED, /**< Firmware Revision String value notification disabled event. */
    BLE_DIS_SOFTWARE_REVISION_STRING_EVT_NOTIFICATION_ENABLED,  /**< Software Revision String value notification enabled event. */
    BLE_DIS_SOFTWARE_REVISION_STRING_EVT_NOTIFICATION_DISABLED, /**< Software Revision String value notification disabled event. */
    BLE_DIS_SYSTEM_ID_EVT_NOTIFICATION_ENABLED,  /**< System ID value notification enabled event. */
    BLE_DIS_SYSTEM_ID_EVT_NOTIFICATION_DISABLED, /**< System ID value notification disabled event. */
    BLE_DIS_IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_EVT_NOTIFICATION_ENABLED,  /**< IEEE 11073-20601 Regulatory Certification Data List value notification enabled event. */
    BLE_DIS_IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_EVT_NOTIFICATION_DISABLED, /**< IEEE 11073-20601 Regulatory Certification Data List value notification disabled event. */
    BLE_DIS_PNP_ID_EVT_NOTIFICATION_ENABLED,  /**< PnP ID value notification enabled event. */
    BLE_DIS_PNP_ID_EVT_NOTIFICATION_DISABLED, /**< PnP ID value notification disabled event. */
} ble_dis_evt_type_t;

// Forward declaration of the ble_dis_t type.
typedef struct ble_dis_s ble_dis_t;






typedef enum
{ 
    VENDOR_ID_SOURCE_BLUETOOTH_SIG_ASSIGNED_COMPANY_IDENTIFIER_VALUE_FROM_THE_ASSIGNED_NUMBERS_DOCUMENT = 1, 
    VENDOR_ID_SOURCE_USB_IMPLEMENTER_S_FORUM_ASSIGNED_VENDOR_ID_VALUE = 2, 
} enum_vendor_id_source_t; 
typedef struct
{
    enum_vendor_id_source_t vendor_id_source; 
} pnp_id_vendor_id_source_t; 


/**@brief Manufacturer Name String structure. */
typedef struct
{
    ble_srv_utf8_str_t manufacturer_name;
} ble_dis_manufacturer_name_string_t;
/**@brief Model Number String structure. */
typedef struct
{
    ble_srv_utf8_str_t model_number;
} ble_dis_model_number_string_t;
/**@brief Serial Number String structure. */
typedef struct
{
    ble_srv_utf8_str_t serial_number;
} ble_dis_serial_number_string_t;
/**@brief Hardware Revision String structure. */
typedef struct
{
    ble_srv_utf8_str_t hardware_revision;
} ble_dis_hardware_revision_string_t;
/**@brief Firmware Revision String structure. */
typedef struct
{
    ble_srv_utf8_str_t firmware_revision;
} ble_dis_firmware_revision_string_t;
/**@brief Software Revision String structure. */
typedef struct
{
    ble_srv_utf8_str_t software_revision;
} ble_dis_software_revision_string_t;
/**@brief System ID structure. */
typedef struct
{
    uint40_t manufacturer_identifier;
    uint24_t organizationally_unique_identifier;
} ble_dis_system_id_t;
/**@brief IEEE 11073-20601 Regulatory Certification Data List structure. */
typedef struct
{
    regcertdatalist_t data;
} ble_dis_ieee_11073_20601_regulatory_certification_data_list_t;
/**@brief PnP ID structure. */
typedef struct
{
    pnp_id_vendor_id_source_t vendor_id_source;
    uint16_t vendor_id;
    uint16_t product_id;
    uint16_t product_version;
} ble_dis_pnp_id_t;

/**@brief Device Information Service event. */
typedef struct
{
    ble_dis_evt_type_t evt_type;    /**< Type of event. */
    union {
        uint16_t cccd_value; /**< Holds decoded data in Notify and Indicate event handler. */
    } params;
} ble_dis_evt_t;

/**@brief Device Information Service event handler type. */
typedef void (*ble_dis_evt_handler_t) (ble_dis_t * p_dis, ble_dis_evt_t * p_evt);

/**@brief Device Information Service init structure. This contains all options and data needed for initialization of the service */
typedef struct
{
    ble_dis_evt_handler_t     evt_handler; /**< Event handler to be called for handling events in the Device Information Service. */
    ble_dis_manufacturer_name_string_t ble_dis_manufacturer_name_string_initial_value; /**< If not NULL, initial value of the Manufacturer Name String characteristic. */ 
    ble_dis_model_number_string_t ble_dis_model_number_string_initial_value; /**< If not NULL, initial value of the Model Number String characteristic. */ 
    ble_dis_serial_number_string_t ble_dis_serial_number_string_initial_value; /**< If not NULL, initial value of the Serial Number String characteristic. */ 
    ble_dis_hardware_revision_string_t ble_dis_hardware_revision_string_initial_value; /**< If not NULL, initial value of the Hardware Revision String characteristic. */ 
    ble_dis_firmware_revision_string_t ble_dis_firmware_revision_string_initial_value; /**< If not NULL, initial value of the Firmware Revision String characteristic. */ 
    ble_dis_software_revision_string_t ble_dis_software_revision_string_initial_value; /**< If not NULL, initial value of the Software Revision String characteristic. */ 
    ble_dis_system_id_t ble_dis_system_id_initial_value; /**< If not NULL, initial value of the System ID characteristic. */ 
    ble_dis_ieee_11073_20601_regulatory_certification_data_list_t ble_dis_ieee_11073_20601_regulatory_certification_data_list_initial_value; /**< If not NULL, initial value of the IEEE 11073-20601 Regulatory Certification Data List characteristic. */ 
    ble_dis_pnp_id_t ble_dis_pnp_id_initial_value; /**< If not NULL, initial value of the PnP ID characteristic. */ 
} ble_dis_init_t;

/**@brief Device Information Service structure. This contains various status information for the service.*/
struct ble_dis_s
{
    ble_dis_evt_handler_t evt_handler; /**< Event handler to be called for handling events in the Device Information Service. */
    uint16_t service_handle; /**< Handle of Device Information Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t manufacturer_name_string_handles; /**< Handles related to the Manufacturer Name String characteristic. */
    ble_gatts_char_handles_t model_number_string_handles; /**< Handles related to the Model Number String characteristic. */
    ble_gatts_char_handles_t serial_number_string_handles; /**< Handles related to the Serial Number String characteristic. */
    ble_gatts_char_handles_t hardware_revision_string_handles; /**< Handles related to the Hardware Revision String characteristic. */
    ble_gatts_char_handles_t firmware_revision_string_handles; /**< Handles related to the Firmware Revision String characteristic. */
    ble_gatts_char_handles_t software_revision_string_handles; /**< Handles related to the Software Revision String characteristic. */
    ble_gatts_char_handles_t system_id_handles; /**< Handles related to the System ID characteristic. */
    ble_gatts_char_handles_t ieee_11073_20601_regulatory_certification_data_list_handles; /**< Handles related to the IEEE 11073-20601 Regulatory Certification Data List characteristic. */
    ble_gatts_char_handles_t pnp_id_handles; /**< Handles related to the PnP ID characteristic. */
    uint16_t conn_handle; /**< Handle of the current connection (as provided by the BLE stack, is BLE_CONN_HANDLE_INVALID if not in a connection). */
};

/**@brief Function for initializing the Device Information.
 *
 * @param[out]  p_dis       Device Information Service structure. This structure will have to be supplied by
 *                          the application. It will be initialized by this function, and will later
 *                          be used to identify this particular service instance.
 * @param[in]   p_dis_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_dis_init(ble_dis_t * p_dis, const ble_dis_init_t * p_dis_init);

/**@brief Function for handling the Application's BLE Stack events.*/
void ble_dis_on_ble_evt(ble_dis_t * p_dis, ble_evt_t * p_ble_evt);

/**@brief Function for setting the Manufacturer Name String.
 *
 * @details Sets a new value of the Manufacturer Name String characteristic. The new value will be sent
 *          to the client the next time the client reads the Manufacturer Name String characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_manufacturer_name_string  New Manufacturer Name String.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_manufacturer_name_string_set(ble_dis_t * p_dis, ble_dis_manufacturer_name_string_t * p_manufacturer_name_string);

/**@brief Function for setting the Model Number String.
 *
 * @details Sets a new value of the Model Number String characteristic. The new value will be sent
 *          to the client the next time the client reads the Model Number String characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_model_number_string  New Model Number String.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_model_number_string_set(ble_dis_t * p_dis, ble_dis_model_number_string_t * p_model_number_string);

/**@brief Function for setting the Serial Number String.
 *
 * @details Sets a new value of the Serial Number String characteristic. The new value will be sent
 *          to the client the next time the client reads the Serial Number String characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_serial_number_string  New Serial Number String.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_serial_number_string_set(ble_dis_t * p_dis, ble_dis_serial_number_string_t * p_serial_number_string);

/**@brief Function for setting the Hardware Revision String.
 *
 * @details Sets a new value of the Hardware Revision String characteristic. The new value will be sent
 *          to the client the next time the client reads the Hardware Revision String characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_hardware_revision_string  New Hardware Revision String.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_hardware_revision_string_set(ble_dis_t * p_dis, ble_dis_hardware_revision_string_t * p_hardware_revision_string);

/**@brief Function for setting the Firmware Revision String.
 *
 * @details Sets a new value of the Firmware Revision String characteristic. The new value will be sent
 *          to the client the next time the client reads the Firmware Revision String characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_firmware_revision_string  New Firmware Revision String.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_firmware_revision_string_set(ble_dis_t * p_dis, ble_dis_firmware_revision_string_t * p_firmware_revision_string);

/**@brief Function for setting the Software Revision String.
 *
 * @details Sets a new value of the Software Revision String characteristic. The new value will be sent
 *          to the client the next time the client reads the Software Revision String characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_software_revision_string  New Software Revision String.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_software_revision_string_set(ble_dis_t * p_dis, ble_dis_software_revision_string_t * p_software_revision_string);

/**@brief Function for setting the System ID.
 *
 * @details Sets a new value of the System ID characteristic. The new value will be sent
 *          to the client the next time the client reads the System ID characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_system_id  New System ID.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_system_id_set(ble_dis_t * p_dis, ble_dis_system_id_t * p_system_id);

/**@brief Function for setting the IEEE 11073-20601 Regulatory Certification Data List.
 *
 * @details Sets a new value of the IEEE 11073-20601 Regulatory Certification Data List characteristic. The new value will be sent
 *          to the client the next time the client reads the IEEE 11073-20601 Regulatory Certification Data List characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_ieee_11073_20601_regulatory_certification_data_list  New IEEE 11073-20601 Regulatory Certification Data List.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_ieee_11073_20601_regulatory_certification_data_list_set(ble_dis_t * p_dis, ble_dis_ieee_11073_20601_regulatory_certification_data_list_t * p_ieee_11073_20601_regulatory_certification_data_list);

/**@brief Function for setting the PnP ID.
 *
 * @details Sets a new value of the PnP ID characteristic. The new value will be sent
 *          to the client the next time the client reads the PnP ID characteristic.
 *          This function is only generated if the characteristic's Read property is not 'Excluded'.
 *
 * @param[in]   p_dis                 Device Information Service structure.
 * @param[in]   p_pnp_id  New PnP ID.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t ble_dis_pnp_id_set(ble_dis_t * p_dis, ble_dis_pnp_id_t * p_pnp_id);

#endif //_BLE_DIS_H__