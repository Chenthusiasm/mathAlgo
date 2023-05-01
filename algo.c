//=== DEPENDENCIES =============================================================

#include "algo.h"

#include "stddef.h"


//=== PRIVATE CONSTANTS ========================================================

static algo_lineSlopeIntercept_t DefaultLine =
{
    .valid = false,
    .slope = 0.0f,
    .yIntercept = 0.0f
};


//=== PRIVATE FUNCTIONS ========================================================

algo_lineSlopeIntercept_t findBestFitLineLinearRegression(
    algo_coordinate_t coordinates[],
    uint32_t size
    )
{
    algo_lineSlopeIntercept_t line = DefaultLine;

    return line;
}

algo_lineSlopeIntercept_t findBestFitLineDemingRegression(
    algo_coordinate_t coordinates[],
    uint32_t size
    )
{
    algo_lineSlopeIntercept_t line = DefaultLine;

    return line;
}


//=== PUBLIC FUNCTIONS =========================================================

algo_lineSlopeIntercept_t algo_findBestFitLine(
    algo_coordinate_t coordinates[],
    uint32_t size,
    algo_bestFitLine_t bestFitLineAlgo
    )
{
    algo_lineSlopeIntercept_t line = DefaultLine;

    // requires at least 2 coordinate-pairs to determine best-fit line
    if ((coordinates != NULL) && (size >= 2u))
    {
        switch (bestFitLineAlgo)
        {
            case algo_bestFitLine_linearRegression:
            {
                line = findBestFitLineLinearRegression(coordinates, size);
                break;
            }

            case algo_bestFitLine_demingRegression:
            {
                line = findBestFitLineDemingRegression(coordinates, size);
                break;
            }

            default:
            {
                // empty; should not get here
            }
        }
    }

    return line;
}
