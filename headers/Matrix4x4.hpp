/**
 * @file Matrix4x4.hpp
 * @author Wojtek B. (wboojztee@gmail.com)
 * @brief Implementation of class template introducing row-major 4x4 Matrix using some of the Scratchapixel exmaple
 * @version 0.1
 * @date 2023-04-17
 * 
 * 
 */

#pragma once

#include "vector3f.hpp"
#include "myMath.hpp"

template <class T>
class Matrix4x4f
{
    private:
       T m[4][4] = {{1.0f,0.0f,0.0f,0.0f}, {0.0f,1.0f,0.0f,0.0f}, {0.0f,0.0f,1.0f,0.0f}, {0.0f,0.0f,0.0f,1.0f}};
    public:
        Matrix4x4f() {}
        Matrix4x4f(T x, T y, T z)
        {
            m[0][0] = x;
            m[1][1] = y;
            m[2][2] = z;
        }

        Matrix4x4f(T x)
        {
            m[0][0] = x;
            m[1][1] = x;
            m[2][2] = x;
            m[3][3] = x;
        }

        Matrix4x4f(T** _m)
        {
            m = _m;
        }
        Matrix4x4f(Vector3f m1, Vector3f m2, Vector3f m3)
        {
            m[0][0] = m1.X();
            m[0][1] = m1.Y();
            m[0][2] = m1.Z();
            m[1][0] = m2.X();
            m[1][1] = m2.Y();
            m[1][2] = m2.Z();
            m[2][0] = m3.X();
            m[2][1] = m3.Y();
            m[2][2] = m3.Z();
        }

        static Matrix4x4f<T> translate(Vector3f Tr)
        {
            Matrix4x4f trans = Matrix4x4f<float>(1.0f);

            trans[3][0] = Tr.X();
            trans[3][1] = Tr.Y();
            trans[3][2] = Tr.Z();

            return trans;
        }

        static Matrix4x4f<T> rotate_y(T angle) 
        {
            float theta = myMath::pointToRadConv<T>(angle);
            float cos_theta = std::cos(theta);
            float sin_theta = std::sin(theta);

            Matrix4x4f rot = Matrix4x4f<float>(1.0f);

            rot[0][0] = cos_theta;
            rot[0][2] = sin_theta;
            rot[2][0] = -sin_theta;
            rot[2][2] = cos_theta;

            return rot;
        }

        static Matrix4x4f<T> rotate_x(T angle) 
        {
            float theta = myMath::pointToRadConv<T>(angle);
            float cos_theta = std::cos(theta);
            float sin_theta = std::sin(theta);

            Matrix4x4f rot = Matrix4x4f<float>(1.0f);

            rot[1][1] = cos_theta;
            rot[1][2] = -sin_theta;
            rot[2][1] = sin_theta;
            rot[2][2] = cos_theta;

            return rot;
        }

        static Matrix4x4f<T> rotate_z(T angle) 
        {
            float theta = myMath::pointToRadConv<T>(angle);
            float cos_theta = std::cos(theta);
            float sin_theta = std::sin(theta);

            Matrix4x4f rot = Matrix4x4f<float>(1.0f);

            rot[0][0] = cos_theta;
            rot[0][1] = -sin_theta;
            rot[1][0] = sin_theta;
            rot[1][1] = cos_theta;

            return rot;
        }

        const T* operator[] (uint8_t i) const {return m[i];}
        T* operator[] (uint8_t i) {return m[i];}
        Matrix4x4f operator * (const Matrix4x4f& mat2)
        {
            Matrix4x4f mult;
            for (uint8_t i = 0; i < 4; i++)
            {
                for (uint8_t j = 0; j < 4; j++)
                {
                    mult[i][j] = m[i][0]*mat2[0][j]
                               + m[i][1]*mat2[1][j]
                               + m[i][2]*mat2[2][j]
                               + m[i][3]*mat2[3][j];
                }
            }
            return mult;
        }

        Matrix4x4f operator * (const Matrix4x4f& mat2) const 
        {
            Matrix4x4f mult;
            for (uint8_t i = 0; i < 4; i++)
            {
                for (uint8_t j = 0; j < 4; j++)
                {
                    mult[i][j] = m[i][0]*mat2[0][j]
                               + m[i][1]*mat2[1][j]
                               + m[i][2]*mat2[2][j]
                               + m[i][3]*mat2[3][j];
                }
            }
            return mult;
        }

        Vector3f operator * (const Vector3f& vector)
        {
            Vector3f dest;

            dest = {vector.X()*m[0][0] + vector.Y() * m[1][0] + vector.Z()*m[2][0] + m[3][0],
                    vector.X()*m[0][1] + vector.Y() * m[1][1] + vector.Z()*m[2][1] + m[3][1],
                    vector.X()*m[0][2] + vector.Y() * m[1][2] + vector.Z()*m[2][2] + m[3][2]};

            T w = vector.X()*m[0][3] + vector.Y()*m[1][3] + vector.Z()*m[2][3] + m[3][3];

            if(w != 1 && w != 0)
            {
                dest = dest/w;
            }
        
            return dest;
        }

        Vector3f muliptlyAsVector (const Vector3f& vector) const
        {
            Vector3f dest;

            dest = {vector.X()*m[0][0] + vector.Y() * m[1][0] + vector.Z()*m[2][0],
                    vector.X()*m[0][1] + vector.Y() * m[1][1] + vector.Z()*m[2][1],
                    vector.X()*m[0][2] + vector.Y() * m[1][2] + vector.Z()*m[2][2]};
        
            return dest;
        }

        Vector3f operator * (const Vector3f& vector) const
        {
            Vector3f dest;

            dest = {vector.X()*m[0][0] + vector.Y() * m[1][0] + vector.Z()*m[2][0] + m[3][0],
                    vector.X()*m[0][1] + vector.Y() * m[1][1] + vector.Z()*m[2][1] + m[3][1],
                    vector.X()*m[0][2] + vector.Y() * m[1][2] + vector.Z()*m[2][2] + m[3][2]};

            T w = vector.X()*m[0][3] + vector.Y()*m[1][3] + vector.Z()*m[2][3] + m[3][3];

            if(w != 1 && w != 0)
            {
                dest = dest/w;
            }
        
            return dest;
        }   

        Matrix4x4f transpose() const
        {
            Matrix4x4f transMat;
            for(uint8_t i = 0; i< 4; i++)
            {
                for (uint8_t j = 0; j < 4; j++)
                {
                    transMat[i][j] = m[j][i];
                }
            }
            return transMat;
        }


/*
* https://github.com/scratchapixel/website/blob/main/lessons/mathematics-physics-for-computer-graphics/matrix-inverse/matrix-inverse.md
*/
        Matrix4x4f<T> inverse() const
        {
            Matrix4x4f<T> s;
            Matrix4x4f<T> t(*this);

            for (uint32_t i = 0; i < 3; i++) 
            {
                uint32_t pivot = i;

                float pivotsize = t[i][i];

                if (pivotsize < 0) pivotsize = -pivotsize;

                for (uint32_t j = i + 1; j < 4; j++) {
                    float tmp = t[j][i];

                    if (tmp < 0) tmp = -tmp;

                    if (tmp > pivotsize) {
                        pivot = j;
                        pivotsize = tmp;
                    }
                }

                if (pivotsize == 0) { return Matrix4x4f<T>(); }

                if (pivot != i) {
                    for (uint32_t j = 0; j < 4; j++) {
                        float tmp;

                        tmp = t[i][j];
                        t[i][j] = t[pivot][j];
                        t[pivot][j] = tmp;

                        tmp = s[i][j];
                        s[i][j] = s[pivot][j];
                        s[pivot][j] = tmp;
                    }
                }

        		// Step 2: eliminate all the numbers below the diagonal
                for (uint32_t j = i + 1; j < 4; j++) {
                    float f = t[j][i] / t[i][i];

                    for (uint32_t k = 0; k < 4; k++) {
                        t[j][k] -= f * t[i][k];
                        s[j][k] -= f * s[i][k];
                    }
        			// Set the column value to exactly 0 in case
        			// numeric roundoff left it a very tiny number
        			t[j][i] = 0.f;
                }
            }

        	// Step 3: set elements along the diagonal to 1.0
        	for (uint32_t i = 0; i < 4; i++) {
        		float divisor = t[i][i];
        		for (uint32_t j = 0; j < 4; j++) {
        			t[i][j] = t[i][j] / divisor;
        			s[i][j] = s[i][j] / divisor;
        		}
        		// set the diagonal to 1.0 exactly to avoid
        		// possible round-off error
        		t[i][i] = 1.f;
        	}

        	// Step 4: eliminate all the numbers above the diagonal
        	for (uint32_t i = 0; i < 3; i++) {
        		for (uint32_t j = i + 1; j < 4; j++) {
        			float constant = t[i][j];
        			for (uint32_t k = 0; k < 4; k++) {
        				t[i][k] -= t[j][k] * constant;
        				s[i][k] -= s[j][k] * constant;
        			}
        			t[i][j] = 0.f;	// in case of round-off error
        		}
        	}

            return s;
        }

        friend std::ostream& operator <<(std::ostream& out, const Matrix4x4f<T>& mat)
        {
            for (int i = 0; i<4; i++)
            {
                std::cout << "|\t";
                for (int j =0; j<4; j++)
                {
                    out<< mat[i][j] << " ";
                }
                out << "\t|\n";        
            }
            return out;
        }
};
