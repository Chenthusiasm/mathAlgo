#ifndef __ALGO_H__
#define __ALGO_H__

//=== DEPENDENCIES =============================================================

#include <stdbool.h>
#include <stdint.h>


//=== TYPE DEFINES =============================================================

/// @brief Data type for the algo module's standard number.
typedef float algo_data_t;

/// @brief Enumeration of the different types of algorithms to determine the
///        best-fit line.
typedef enum
{
    /// @brief Use the standard linear regression algorithm.
    /// @link https://en.wikipedia.org/wiki/Simple_linear_regression
    algo_bestFitLine_linearRegression = 0u,

    /// @brief Use the Deming regression which accounts for errors in both the
    ///        x and y axis.
    /// @link https://en.wikipedia.org/wiki/Deming_regression
    algo_bestFitLine_demingRegression,

} algo_bestFitLine_t;

/// @brief Structure for the x-y coordinate pair. 
typedef struct algo_coordinate_t
{
    /// @brief x-coordinate
    algo_data_t x;

    /// @brief y-coordinate
    algo_data_t y;

} algo_coordinate_t;

/// @brief Structure to describe a line in slope-intercept form: y = mx + b
typedef struct algo_lineSlopeIntercept_t
{
    /// @brief flag indicating if the line is valid (exists and is linear)
    bool valid;

    /// @brief slope
    algo_data_t slope;

    /// @brief y-intercept
    algo_data_t yIntercept;

} algo_lineSlopeIntercept_t;


//=== FUNCTION PROTOTYPES ======================================================

/// @brief Finds slope-intercept form of the best-fit line given a set of
///        coodinate pairs.
/// @param coordinates Array of coordinate pairs.
/// @param size The number of coordinate pairs in the coordinates parameter.
/// @param bestFitLineAlgo The best-fit line algorithm to use. 
/// @return The slope-intercept structure of the best-fit line.
algo_lineSlopeIntercept_t algo_findBestFitLine(
    algo_coordinate_t coordinates[],
    uint32_t size,
    algo_bestFitLine_t bestFitLineAlgo
    );


#endif // __ALGO_H__
