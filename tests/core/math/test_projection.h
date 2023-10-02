/**************************************************************************/
/*  test_projection.h                                                     */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_PROJECTION_H
#define TEST_PROJECTION_H

#include "core/math/projection.h"

#include "tests/test_macros.h"
#include "tests/test_utils.h"

namespace TestProjection {
const float tolerance = 0.01;

TEST_CASE("[Projection] Determinant") {
	SUBCASE("Identity Matrix") {
		Projection projection = Projection();
		projection.set_identity();

		const float determinant = projection.determinant();
		CHECK(determinant == 1);
	}
	SUBCASE("Zero Matrix") {
		Projection projection = Projection();
		projection.set_zero();

		const float determinant = projection.determinant();
		CHECK(determinant == 0);
	}
	SUBCASE("Light Bias") {
		Projection projection = Projection();
		projection.set_light_bias();

		const float determinant = projection.determinant();
		CHECK(determinant == 0.125);
	}
}

TEST_CASE("[Projection] Operator overload []") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection]") {
}

TEST_CASE("[Projection] Flip Y") {
        Projection projectionMatrix;

        // Set an initial projection matrix with some values
        projectionMatrix.columns[0][0] = 1.0;
        projectionMatrix.columns[1][1] = 2.0;
        projectionMatrix.columns[2][2] = 3.0;
        projectionMatrix.columns[3][3] = 1.0;

        // Perform the Y-axis flip operation
        projectionMatrix.flip_y();

        // Check that the Y-axis elements have been correctly flipped
        CHECK(projectionMatrix.columns[1][0] == -2.0);
        CHECK(projectionMatrix.columns[1][1] == -4.0); // Y-axis element flipped
        CHECK(projectionMatrix.columns[1][2] == -6.0); // Y-axis element flipped
        CHECK(projectionMatrix.columns[1][3] == -1.0);

        // Check that other elements remain unchanged
        CHECK(projectionMatrix.columns[0][0] == 1.0);
        CHECK(projectionMatrix.columns[2][2] == 3.0);
        CHECK(projectionMatrix.columns[3][3] == 1.0);
}

TEST_CASE("[Projection] Multiplication Operator") {
        SUBCASE("Matrix Multiplication - Identity Matrix") {
            Projection identityMatrix;
            identityMatrix.set_identity();

            Projection matrix1;
            matrix1.make_scale(Vector3(2.0, 2.0, 2.0)); // Scaling matrix

            Projection result = matrix1 * identityMatrix;

            // Check that multiplying by the identity matrix leaves the matrix unchanged
            CHECK(result == matrix1);
        }

        SUBCASE("Matrix Multiplication - Translation Matrices") {
            Projection translationMatrix1;
            translationMatrix1.set_light_bias(); // Translation matrix 1

            Projection translationMatrix2;
            translationMatrix2.set_light_atlas_rect(Rect2(1.0, 2.0, 0.0, 0.0)); // Translation matrix 2

            Projection result = translationMatrix1 * translationMatrix2;

            // Check that multiplying two translation matrices combines their translations
            CHECK(result.columns[3][0] == 1.0);
            CHECK(result.columns[3][1] == 1.5);
            CHECK(result.columns[3][2] == 0.5);
        }

        SUBCASE("Matrix Multiplication - Scaling Matrices") {
            Projection matrix1;
            matrix1.make_scale(Vector3(2.0, 2.0, 2.0)); // Scaling matrix

            Projection matrix2;
            matrix2.make_scale(Vector3(0.5, 0.5, 0.5)); // Scaling matrix

            Projection result = matrix1 * matrix2;

            // Check that multiplying two scaling matrices combines their scaling factors
            CHECK(result.columns[0][0] == 1.0);
            CHECK(result.columns[1][1] == 1.0);
            CHECK(result.columns[2][2] == 1.0);
        }

}

TEST_CASE("[Projection] Set depth projection") {
	SUBCASE("Flip Y") {
		Projection proj;
		proj.set_depth_correction(true);

        CHECK(proj[0][0] == 1.0);
        CHECK(proj[0][1] == 0.0);
        CHECK(proj[0][2] == 0.0);
        CHECK(proj[0][3] == 0.0);

        CHECK(proj[1][0] == 0.0);
        CHECK(proj[1][1] == -1.0);
        CHECK(proj[1][2] == 0.0);
        CHECK(proj[1][3] == 0.0);

        CHECK(proj[2][0] == 0.0);
        CHECK(proj[2][1] == 0.0);
        CHECK(proj[2][2] == 0.5);
        CHECK(proj[2][3] == 0.0);

        CHECK(proj[3][0] == 0.0);
        CHECK(proj[3][1] == 0.0);
        CHECK(proj[3][2] == 0.5);
        CHECK(proj[3][3] == 1.0);
	}
	SUBCASE("No Flip Y") {
		Projection proj;
		proj.set_depth_correction(false);

        CHECK(proj[0][0] == 1.0);
        CHECK(proj[0][1] == 0.0);
        CHECK(proj[0][2] == 0.0);
        CHECK(proj[0][3] == 0.0);

        CHECK(proj[1][0] == 0.0);
        CHECK(proj[1][1] == 1.0);
        CHECK(proj[1][2] == 0.0);
        CHECK(proj[1][3] == 0.0);

        CHECK(proj[2][0] == 0.0);
        CHECK(proj[2][1] == 0.0);
        CHECK(proj[2][2] == 0.5);
        CHECK(proj[2][3] == 0.0);

        CHECK(proj[3][0] == 0.0);
        CHECK(proj[3][1] == 0.0);
        CHECK(proj[3][2] == 0.5);
        CHECK(proj[3][3] == 1.0);
	}
}

TEST_CASE("[Projection] Set light bias") {
	Projection projection = Projection();
	projection.set_light_bias();

	// Access the modified matrix.
	const real_t *m = &projection.columns[0][0];

	// Define the expected values for the matrix.
	real_t expectedMatrix[16] = {
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	};

	// Check if the matrix elements match the expected values
	for (int i = 0; i < 16; i++) {
		CHECK(m[i] == expectedMatrix[i]);
	}
}

TEST_CASE("[Projection] Set light atlas rectangle") {
	Projection projection;

	// Define a Rect2 for testing
	Rect2 rect(Vector2(10.0, 20.0), Vector2(30.0, 40.0));

	// Set the light atlas rect
	projection.set_light_atlas_rect(rect);

	// Define the expected matrix values
	real_t expectedMatrix[16] = {
		30.0, 0.0, 0.0, 0.0,
		0.0, 40.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		10.0, 20.0, 0.0, 1.0
	};

	// Check if the matrix matches the expected values
	for (int i = 0; i < 16; ++i) {
		CHECK_EQ(projection.columns[0][i], expectedMatrix[i]);
	}
}

TEST_CASE("[Projection] String operator") {
	// Create a test Projection object with known values
	Projection proj;
	proj.set_identity();

	// Convert the Projection to a String
	String str = proj;

	// Define the expected string representation
	String expected_str = "\n1, 0, 0, 0\n0, 1, 0, 0\n0, 0, 1, 0\n0, 0, 0, 1";

	// Check if the generated string matches the expected string
	CHECK(str == expected_str);
}

TEST_CASE("[Projection] Get aspect") {
	// Create a Projection instance (you can replace this with your actual projection setup)
	Projection projection = Projection::create_perspective(60.0, 1.0, 0.1, 1000.0);

	// Set the desired viewport half extents for the test
	Vector2 viewportHalfExtents(1920, 1080); // Replace with your desired values

	// Calculate the expected aspect ratio value
	// The result is calculated as vp_he.x / vp_he.y
	// You can replace this with the expected value for your projection setup
	real_t expectedAspect = viewportHalfExtents.x / viewportHalfExtents.y;

	projection.set_orthogonal(0.0, 1920.0, 0.0, 1080.0, -1.0, 1.0); // Adjust the values as needed

	// Get the actual aspect ratio using the Projection method
	real_t actualAspect = projection.get_aspect();

	// Check if the actual value matches the expected value
	CHECK(abs(actualAspect - expectedAspect) < tolerance);
}

TEST_CASE("[Projection] Get pixels per meter") {
	SUBCASE("With Identity Projection") {
		// Create an identity projection matrix (no transformation)
		Projection identity_projection;
		identity_projection.set_identity();

		// Call get_pixels_per_meter with a pixel width of 1920
		int pixels_per_meter = identity_projection.get_pixels_per_meter(1920);

		// Assert that the result is as expected (should be 1920)
		CHECK(pixels_per_meter == 1920);
	}

	SUBCASE("With Custom Projection") {
		// Create a custom projection matrix with translation
		Projection custom_projection;
		custom_projection.columns[0] = Vector4(-1.0, 0.0, 0.0, 0.0);
		custom_projection.columns[1] = Vector4(0.0, 0.0, 0.0, 0.0);
		custom_projection.columns[2] = Vector4(0.0, 0.0, -1.0, 0.0);
		custom_projection.columns[3] = Vector4(0.0, 0.0, 0.0, 1.0);

		// Call get_pixels_per_meter with a pixel width of 1920
		int pixels_per_meter = custom_projection.get_pixels_per_meter(1920);

		// Assuming the transformation results in Vector3(-1, 0, -1)
		// The expected result would be int((-1 * 0.5 + 0.5) * 1920) = int(0 * 1920) = 0
		CHECK(pixels_per_meter == 0);
	}
}

TEST_CASE("[Projection] Check if orthogonal") {
	SUBCASE("Projection is orthogonal") {
		// Create an orthogonal Projection
		Projection orthogonalProjection = Projection::create_orthogonal(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

		// Check if the orthogonal Projection is indeed orthogonal
		CHECK(orthogonalProjection.is_orthogonal());
	}
	SUBCASE("Projection is not orthogonal") {
		Projection projection;

		// Modify the Projection to make it non-orthogonal
		projection.set_perspective(45.0, 1.0, 0.1, 1000.0);

		// Check if the modified Projection is non-orthogonal
		CHECK_FALSE(projection.is_orthogonal());
	}
}

TEST_CASE("[Projection] Get FOV") {
	SUBCASE("90 degrees") {
		// Create a Projection instance with a 45-degree FOV
		Projection projection = Projection::create_perspective(90.0, 1.0, 0.1, 1000.0);

		// Calculate the expected FOV
		const real_t expected_fov = 90;

		// Get the FOV using the Projection method
		const real_t actual_fov = projection.get_fov();

		// Check if the actual FOV matches the expected FOV in radians
		CHECK(abs(actual_fov - expected_fov) < tolerance);
	}

	SUBCASE("45 degrees") {
		// Create a Projection instance with a 45-degree FOV
		Projection projection = Projection::create_perspective(45.0, 1.0, 0.1, 1000.0);

		// Calculate the expected FOV
		const real_t expected_fov = 45;

		// Get the FOV using the Projection method
		const real_t actual_fov = projection.get_fov();

		// Check if the actual FOV matches the expected FOV in radians
		CHECK(abs(actual_fov - expected_fov) < tolerance);
	}
}

TEST_CASE("[Projection] Get LOD multiplier") {
	Projection projection;
	SUBCASE("Orthogonal") {
		projection.set_orthogonal(-1.0, 1.0, -1.0, 1.0, 0.1, 1000.0);

		const float expected_value = 1.0f;

		// Calculate the LOD multiplier
		float lod_multiplier = projection.get_lod_multiplier();

		// Check if the calculated LOD multiplier is close to the expected value
		CHECK_EQ(lod_multiplier, expected_value);
	}

	SUBCASE("Not Orthogonal") {
		projection.set_perspective(60.0, 16.0 / 9.0, 0.1, 1000.0);

		const float expected_value = 2.0528f;

		// Calculate the LOD multiplier
		float lod_multiplier = projection.get_lod_multiplier();

		// Check if the calculated LOD multiplier is close to the expected value
		CHECK(abs(expected_value - lod_multiplier) < tolerance);
	}
}

TEST_CASE("[Projection] Make scale") {
	// Create an instance of your Projection class
	Projection projection;

	// Define the scaling factors
	Vector3 scaleFactors(2.0, 0.5, 1.5); // Example scaling factors

	// Apply the scaling transformation using the make_scale method
	projection.make_scale(scaleFactors);

	// Check matrix elements
	CHECK_EQ(projection.columns[0][0], scaleFactors.x);
	CHECK_EQ(projection.columns[1][1], scaleFactors.y);
	CHECK_EQ(projection.columns[2][2], scaleFactors.z);

	// Check other matrix elements
	CHECK_EQ(projection.columns[0][1], 0.0);
	CHECK_EQ(projection.columns[0][2], 0.0);
	CHECK_EQ(projection.columns[0][3], 0.0);

	CHECK_EQ(projection.columns[1][0], 0.0);
	CHECK_EQ(projection.columns[1][2], 0.0);
	CHECK_EQ(projection.columns[1][3], 0.0);

	CHECK_EQ(projection.columns[2][0], 0.0);
	CHECK_EQ(projection.columns[2][1], 0.0);
	CHECK_EQ(projection.columns[2][3], 0.0);

	CHECK_EQ(projection.columns[3][0], 0.0);
	CHECK_EQ(projection.columns[3][1], 0.0);
	CHECK_EQ(projection.columns[3][2], 0.0);
	CHECK_EQ(projection.columns[3][3], 1.0);
}

TEST_CASE("[Projection] Scale translate to fit") {
	// Create an AABB to use as input
	AABB aabb(Vector3(-1.0, -1.0, -1.0), Vector3(1.0, 1.0, 1.0));

	// Call the scale_translate_to_fit method
	Projection projection;
	projection.scale_translate_to_fit(aabb);

	// Add your assertions to check if the transformation matrix is set correctly
	// For example, you can access the 'columns' matrix and compare its values
	// with expected values based on the input AABB and scaling/translation logic.

	// Example assertions (modify as needed based on your code):
	CHECK_EQ(projection.columns[0][0], 2.0f); // Check scaling along X-axis
	CHECK_EQ(projection.columns[1][1], 2.0f); // Check scaling along Y-axis
	CHECK_EQ(projection.columns[2][2], 2.0f); // Check scaling along Z-axis
	CHECK_EQ(projection.columns[3][0], 1.0f); // Check translation along X-axis TODO Confirm
	CHECK_EQ(projection.columns[3][1], 1.0f); // Check translation along Y-axis TODO Confirm
	CHECK_EQ(projection.columns[3][2], 1.0f); // Check translation along Z-axis TODO Confirm
	CHECK_EQ(projection.columns[3][3], 1.0f); // Check homogeneous transformation
}

TEST_CASE("[Projection] Add jitter offset") {
	Projection projection = Projection();
	projection.set_zero();

	Vector2 jitter_offset = Vector2(1, 1);
	projection.add_jitter_offset(jitter_offset);

	CHECK_EQ(jitter_offset.x, projection.columns[3][0]);
	CHECK_EQ(jitter_offset.y, projection.columns[3][1]);
}

TEST_CASE("[Projection] Transform3D Operator") {
}

TEST_CASE("[Projection] Constructor - 4 Vector4s") {
	// Create four Vector4 instances to pass as input
	const Vector4 vec1(1.0, 2.0, 3.0, 4.0);
	const Vector4 vec2(5.0, 6.0, 7.0, 8.0);
	const Vector4 vec3(9.0, 10.0, 11.0, 12.0);
	const Vector4 vec4(13.0, 14.0, 15.0, 16.0);

	// Create a Projection object using the constructor
	const Projection projection(vec1, vec2, vec3, vec4);

	// Compare the Projection's columns to the input vectors.
	CHECK_EQ(projection.columns[0], vec1);
	CHECK_EQ(projection.columns[1], vec2);
	CHECK_EQ(projection.columns[2], vec3);
	CHECK_EQ(projection.columns[3], vec4);
}

TEST_CASE("[Projection] Constructor - Transform3D") {
}

} //namespace TestProjection

#endif // TEST_PROJECTION_H