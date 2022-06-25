//Collision.cpp
#include "Collision.h"
#include "Vector2.h"
#include "Vectors.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

namespace sdlUtility {
    namespace Collision {
        /// Used to calculate a drag force for moving objects.
        /** @param Velocity The velocity of the moving object.
            @param DragCoefficient A drag coefficient.
            @param Area The area of the object subjected to the drag force. */
        float CalculateDrag(float Velocity, float DragCoefficient, float Area) {
            return 0.5f*powf(Velocity, 2)*DragCoefficient*Area;
        }

        /// Used to check for collision between two disks.
        /** @param X1, Y1, X2, Y2 Coordinates of each disk.
            @param R1, R2 External radius of each disk.
            @param r1, r2 Internal radius of each disk.
            @param Angle1, Angle2 Section (in radians) of each disk to be considered in the collision check.
            @param Direction1, Direction2 Direction (in radians) to which each disk is pointing. Relevant if using a section of a disk.
            @param AdjustX, AdjustY Measured overlap between the two disks. Values returned by reference. */
        bool DiskInDisk(float X1, float Y1, float R1, float r1, float Angle1, float Direction1, float X2, float Y2, float R2, float r2, float Angle2, float Direction2, float &AdjustX, float &AdjustY) {
            bool DiskInDisk = false;

            float OuterR1 = R1, InnerR1 = r1;
            if (InnerR1 > OuterR1) { OuterR1 = r1; InnerR1 = R1; } else if (InnerR1 == OuterR1) InnerR1 = 0.f;

            float OuterR2 = R2, InnerR2 = r2;
            if (InnerR2 > OuterR2) { OuterR2 = r2; InnerR2 = R2; } else if (InnerR2 == OuterR2) InnerR2 = 0.f;

            float DistanceX = X1-X2;
            float DistanceY = Y1-Y2;

            float Distance = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

            float Overlap = OuterR1+OuterR2-Distance;

            if (Overlap >= 0) {
                if (!((InnerR1 && InnerR1 > OuterR2 && InnerR1 > Distance) || (InnerR2 && InnerR2 > OuterR1 && InnerR2 > Distance))) {
                    DiskInDisk = true;

                    if (fabs(DistanceX) > fabs(DistanceY)) {
                        if (DistanceX < 0) AdjustX = Overlap; else AdjustX = -Overlap;
                    } else if (fabs(DistanceX) < fabs(DistanceY)) {
                        if (DistanceY < 0) AdjustY = Overlap; else AdjustY = -Overlap;
                    }

                    if (DiskInDisk) {
                        if (Angle1 && Angle2) {
                            DiskInDisk = false;
                            AdjustX = AdjustY = 0;

                            float Angle1Min = Direction1-Angle1/2.f, Angle1Max = Direction1+Angle1/2.f;
                            float Angle2Min = Direction2-Angle2/2.f, Angle2Max = Direction2+Angle2/2.f;

                            if (Angle1Min < 0) {
                                Angle1Min += 2*M_PI;
                                Angle1Max += 2*M_PI;
                            }

                            if (Angle2Min < 0) {
                                Angle2Min += 2*M_PI;
                                Angle2Max += 2*M_PI;
                            }

                            float CosProduct = cosf(Direction1)*cosf(Direction2), SinProduct = sinf(Direction1)*sinf(Direction2);

                            if (Distance < OuterR1) {
                                float Angle = atan2f(Y2-Y1, X2-X1)+M_PI/2.f; if (Angle < 0) Angle += 2*M_PI; else if (Angle1Max > 2*M_PI) Angle += 2*M_PI;
                                if (Angle >= Angle1Min && Angle <= Angle1Max) {
                                    DiskInDisk = true;
                                }
                            } else {
                                if (CosProduct < 0 && SinProduct < 0) {
                                    DiskInDisk = true;
                                }
                            }
                        } else if (Angle1 || Angle2) {
                            DiskInDisk = false;
                            AdjustX = AdjustY = 0;

                            float Angle = Angle1?Angle1:Angle2;
                            float AngleMin = Direction1-Angle/2.f;
                            float AngleMax = Direction1+Angle/2.f;

                            if (AngleMin < 0) {
                                AngleMin += 2*M_PI;
                                AngleMax += 2*M_PI;
                            }

                            float XA = X2+cosf(M_PI/2.f)*R2; float YA = Y2+sinf(M_PI/2.f)*R2;
                            float AngleA = atan2f(YA-Y1, XA-X1)+M_PI/2.f; if (AngleA < 0) AngleA += 2*M_PI; else if (AngleMax > 2*M_PI) AngleA += 2*M_PI;

                            //std::cout << AngleA*180.f/M_PI << " " << AngleMin*180.f/M_PI << " " << AngleMax*180/M_PI << std::endl;

                            if (AngleA >= AngleMin && AngleA <= AngleMax) {
                                DiskInDisk = true;
                            } else {
                                float XB = X2+cosf(M_PI+M_PI/2.f)*R2; float YB = Y2+sinf(M_PI+M_PI/2.f)*R2;
                                float AngleB = atan2f(YB-Y1, XB-X1)+M_PI/2.f; if (AngleB < 0) AngleB += 2*M_PI; else if (AngleMax > 2*M_PI) AngleB += 2*M_PI;

                                if (AngleB >= AngleMin && AngleB <= AngleMax) {
                                    DiskInDisk = true;
                                }
                            }
                        }
                    }
                }
            } else {
                float Atan2f = atan2f(DistanceY, DistanceX);
                AdjustX = DistanceX-cosf(Atan2f)*OuterR1;
                AdjustY = DistanceY-sinf(Atan2f)*OuterR1;
            }

            return DiskInDisk;
        }

        /// Used to check for collision between a disk and a rectangle.
        /** @param X1, Y1, X2, Y2 Coordinates of each shape.
            @param R1 External radius of the disk.
            @param r1 Internal radius of the disk.
            @param Angle1 Section (in radians) of the disk to be considered in the collision check.
            @param Direction1, Direction2 Direction (in radians) to which each shape is pointing.
            @param AdjustX, AdjustY Measured overlap between the two shapes. Values returned by reference. */
        bool DiskInRectangle(float X1, float Y1, float R1, float r1, float Angle1, float Direction1, float X2, float Y2, int Width2, int Height2, float Direction2, float &AdjustX, float &AdjustY) {
            bool DiskInRectangle = false;

            float OuterR = R1, InnerR = r1;
            if (InnerR > OuterR) { OuterR = r1; InnerR = R1; } else if (InnerR == OuterR) InnerR = 0.f;

            if (Direction2) RotatePointBy(X1, Y1, X2+(Width2)/2.f, Y2+(Height2)/2.f, -Direction2);

            float ClosestX = Clamp(X2, X1, X2+Width2);
            float ClosestY = Clamp(Y2, Y1, Y2+Height2);

            float DistanceX = X1-ClosestX;
            float DistanceY = Y1-ClosestY;

            float Distance = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

            float Overlap = OuterR-Distance;

            if (Overlap >= 0) {
                DiskInRectangle = true;

                float DifferenceX = OuterR-fabs(DistanceX);
                float DifferenceY = OuterR-fabs(DistanceY);

                //TEMP hack for reactangle edges
                if (fabs(DifferenceX) < fabs(DifferenceY)) {
                    if (fabs(DifferenceX) > fabs(Overlap) && DifferenceX < OuterR) DifferenceX = Overlap;
                } else if (fabs(DifferenceX) > fabs(DifferenceY)) {
                    if (fabs(DifferenceY) > fabs(Overlap) && DifferenceY < OuterR) DifferenceY = Overlap;
                }

                if (DistanceX < 0) AdjustX = DifferenceX; else AdjustX = -DifferenceX;
                if (DistanceY < 0) AdjustY = DifferenceY; else AdjustY = -DifferenceY;

                if (InnerR) {
                    DiskInRectangle = false;
                    AdjustX = AdjustY = 0;

                    std::vector <Vector2> Points;

                    Points.push_back(Vector2(X2, Y2));
                    Points.push_back(Vector2(X2+Width2, Y2));
                    Points.push_back(Vector2(X2+Width2, Y2+Height2));
                    Points.push_back(Vector2(X2, Y2+Height2));

                    std::vector<float> DistancesSq;
                    DistancesSq.push_back(powf(X1-Points[0].X(), 2)+powf(Y1-Points[0].Y(), 2));
                    DistancesSq.push_back(powf(X1-Points[1].X(), 2)+powf(Y1-Points[1].Y(), 2));
                    DistancesSq.push_back(powf(X1-Points[2].X(), 2)+powf(Y1-Points[2].Y(), 2));
                    DistancesSq.push_back(powf(X1-Points[3].X(), 2)+powf(Y1-Points[3].Y(), 2));

                    int Maximum = Vectors::FindMaximum(DistancesSq);

                    float FarthestX = Points[Maximum].X();
                    float FarthestY = Points[Maximum].Y();

                    float Distance2X = X1-FarthestX;
                    float Distance2Y = Y1-FarthestY;

                    float Distance2 = sqrt(pow(Distance2X, 2) + pow(Distance2Y, 2));

                    if (Distance2 >= InnerR) {
                        DiskInRectangle = true;
                    }
                }

                if (DiskInRectangle && Angle1) {
                    DiskInRectangle = false;
                    AdjustX = AdjustY = 0;

                    float AngleMin = Direction1-Direction2-Angle1/2.f, AngleMax = Direction1-Direction2+Angle1/2.f;

                    if (AngleMin < 0) {
                        AngleMin += 2*M_PI;
                        AngleMax += 2*M_PI;
                    }

                    float AngleA = atan2f(Y2-Y1, X2-X1)+M_PI/2.f;  if (AngleA < 0) AngleA += 2*M_PI; else if (AngleMax > 2*M_PI) AngleA += 2*M_PI;

                    if (AngleA >= AngleMin && AngleA <= AngleMax) {
                        DiskInRectangle = true;
                    } else {
                        float AngleB = atan2f(Y2-Y1, X2+Width2-X1)+M_PI/2.f; if (AngleB < 0) AngleB += 2*M_PI; else if (AngleMax > 2*M_PI) AngleB += 2*M_PI;

                        if (AngleB >= AngleMin && AngleB <= AngleMax) {
                            DiskInRectangle = true;
                        } else {
                            float AngleC = atan2f(Y2+Height2-Y1, X2+Width2-X1)+M_PI/2.f; if (AngleC < 0) AngleC += 2*M_PI; else if (AngleMax > 2*M_PI) AngleC += 2*M_PI;

                            if (AngleC >= AngleMin && AngleC <= AngleMax) {
                                DiskInRectangle = true;
                            } else {
                                float AngleD = atan2f(Y2+Height2-Y1, X2-X1)+M_PI/2.f; if (AngleD < 0) AngleD += 2*M_PI; else if (AngleMax > 2*M_PI) AngleD += 2*M_PI;

                                if (AngleD >= AngleMin && AngleD <= AngleMax) {
                                    DiskInRectangle = true;
                                }
                            }
                        }
                    }
                }
            } else {
                if (Direction2) RotatePointBy(ClosestX, ClosestY, X1, Y1, Direction2);
                AdjustX = X1-ClosestX;
                AdjustY = Y1-ClosestY;
            }

            return DiskInRectangle;
        }

        /// Used to keep a float value within a specified range.
        /** @param Minimum Minimum value of the range.
            @param Value Specified value.
            @param Maximum Maximum value of the range. */
        float Clamp(float Minimum, float Value, float Maximum) {
            if (Value > Maximum) {
                Value = Maximum;
            } else if (Value < Minimum) {
                Value = Minimum;
            }

            return Value;
        }

        /// Used to check for collision between a point and a disk.
        /** @param X1, Y1, X, Y Coordinates of each shape.
            @param R External radius of the disk.
            @param r Internal radius of the disk.
            @param Angle Section (in radians) of the disk to be considered in the collision check.
            @param Direction Direction (in radians) to which the disk is pointing. */
        bool PointInDisk(float X1, float Y1, float X, float Y, float R, float r, float Angle, float Direction) {
            bool PointInDisk = false;

            float OuterR = R, InnerR = r;
            if (InnerR > OuterR) { OuterR = r; InnerR = R; } else if (InnerR == OuterR) InnerR = 0.f;

            float DistanceX = X1-X;
            float DistanceY = Y1-Y;

            float Distance = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

            if (Distance <= OuterR+1) {
                PointInDisk = true;

                if (InnerR) {
                    PointInDisk = false;

                    if (Distance > InnerR) {
                        PointInDisk = true;
                    }
                }

                if (PointInDisk && Angle) {
                    PointInDisk = false;
                    float AngleMin = Direction-Angle/2.f, AngleMax = Direction+Angle/2.f;

                    if (AngleMin < 0) {
                        AngleMin += 2.f*M_PI;
                        AngleMax += 2.f*M_PI;
                    }

                    float AngleP = atan2f(Y1-Y, X1-X)+M_PI/2.f;  if (AngleP < 0) AngleP += 2*M_PI; else if (AngleMax > 2*M_PI) AngleP += 2*M_PI;

                    if (AngleP >= AngleMin && AngleP <= AngleMax) {
                        PointInDisk = true;
                    }
                }
            }

            return PointInDisk;
        }

        /// Used to check for collision between a point and a rectangle.
        /** @param X1, Y1, X, Y Coordinates of each shape.
            @param Width, Height Dimensions of the rectangle.
            @param Direction Direction (in radians) to which the rectangle is pointing. */
        bool PointInRectangle(float X1, float Y1, float X, float Y, int Width, int Height, float Direction) {
            bool PointInRectangle = false;

            if (Direction) RotatePointBy(X1, Y1, X+(Width)/2.f, Y+(Height)/2.f, -Direction);

            if (X1 > X && X1 < X+Width && Y1 > Y && Y1 < Y+Height) { //= for precise pixel detection
                PointInRectangle = true;
            }

            return PointInRectangle;
        }

        /// Used to check for collision between a point and an isosceles triangle.
        /** @param X1, Y1, X, Y Coordinates of each shape.
            @param Width, Height Dimensions of the triangle.
            @param Direction Direction (in radians) to which the triangle is pointing. */
        bool PointInTriangle(float X1, float Y1, float X, float Y, int Width, int Height, float Direction) {
            bool PointInTriangle = false;

            if (Direction) RotatePointBy(X1, Y1, X+Width/2.f, Y+Height/2.f, -Direction);

            if (X1 > X+Width/2.f/Height*(Y1-Y) && X1 < X+Width-Width/2.f/Height*(Y1-Y) && Y1 > Y && Y1 < Y+Height) {
                PointInTriangle = true;
            }

            return PointInTriangle;
        }

        /// Used to check for collision between a point and a rectangle.
        /** @param X1, Y1, X2, Y2 Coordinates of each rectangle.
            @param Width1, Height1, Width2, Height2, Dimensions of each rectangle.
            @param Direction1, Direction2 Direction (in radians) to which each rectangle is pointing.
            @param AdjustX, AdjustY Measured overlap between the two rectangles. Values returned by reference. */
        bool RectangleInRectangle(float X1, float Y1, int Width1, int Height1, float Direction1, float X2, float Y2, int Width2, int Height2, float Direction2, float &AdjustX, float &AdjustY) {
            bool RectangleInRectangle = false;


            if (Direction1 || Direction2) {
                //Vector Adjust;

                //Fast Check
                float CenterX1 = X1+Width1/2.f, CenterY1 = Y1+Height1/2.f;
                float CenterX2 = X2+Width2/2.f, CenterY2 = Y2+Height2/2.f;

                float Diagonal1 = pow(Width1, 2)+pow(Height1, 2), Diagonal2 = pow(Width2, 2)+pow(Height2, 2); //Not Rooted for performance
                float Distance = pow(CenterX1-CenterX2, 2)+pow(CenterY1-CenterY2, 2); //Not Rooted for performance

                if (Distance <= (Diagonal1+Diagonal2)/4.f) {
                    float X11 = X1, Y11 = Y1;
                    float X12 = X1+Width1, Y12 = Y1;
                    float X13 = X1+Width1, Y13 = Y1+Height1;
                    float X14 = X1, Y14 = Y1+Height1;

                    if (Direction1) {
                        RotatePointBy(X11, Y11, CenterX1, CenterY1, Direction1);
                        RotatePointBy(X12, Y12, CenterX1, CenterY1, Direction1);
                        RotatePointBy(X13, Y13, CenterX1, CenterY1, Direction1);
                        RotatePointBy(X14, Y14, CenterX1, CenterY1, Direction1);
                    }

                    float X21 = X2, Y21 = Y2;
                    float X22 = X2+Width2, Y22 = Y2;
                    float X23 = X2+Width2, Y23 = Y2+Height2;
                    float X24 = X2, Y24 = Y2+Height2;

                    if (Direction2) {
                        RotatePointBy(X21, Y21, CenterX2, CenterY2, Direction2);
                        RotatePointBy(X22, Y22, CenterX2, CenterY2, Direction2);
                        RotatePointBy(X23, Y23, CenterX2, CenterY2, Direction2);
                        RotatePointBy(X24, Y24, CenterX2, CenterY2, Direction2);
                    }

                    bool Overlap = true;

                    std::vector<Vector2> Axes;
                    Axes.push_back(Vector2(X12-X11, Y12-Y11));
                    Axes.push_back(Vector2(X12-X13, Y12-Y13));
                    Axes.push_back(Vector2(X21-X24, Y21-Y24));
                    Axes.push_back(Vector2(X21-X22, Y21-Y22));

                    unsigned int i=0;
                    while (Overlap and i<Axes.size()) {
                        float AxisX = Axes[i].X(), AxisY = Axes[i].Y();


                        float AxisXYSquared = pow(AxisX, 2)+pow(AxisY, 2);

                        std::vector<Vector2> Projections1;
                        Projections1.push_back(Vector2((X11*AxisX+Y11*AxisY)/AxisXYSquared*AxisX, (X11*AxisX+Y11*AxisY)/AxisXYSquared*AxisY));
                        Projections1.push_back(Vector2((X12*AxisX+Y12*AxisY)/AxisXYSquared*AxisX, (X12*AxisX+Y12*AxisY)/AxisXYSquared*AxisY));
                        Projections1.push_back(Vector2((X13*AxisX+Y13*AxisY)/AxisXYSquared*AxisX, (X13*AxisX+Y13*AxisY)/AxisXYSquared*AxisY));
                        Projections1.push_back(Vector2((X14*AxisX+Y14*AxisY)/AxisXYSquared*AxisX, (X14*AxisX+Y14*AxisY)/AxisXYSquared*AxisY));

                        std::vector<Vector2> Projections2;
                        Projections2.push_back(Vector2((X21*AxisX+Y21*AxisY)/AxisXYSquared*AxisX, (X21*AxisX+Y21*AxisY)/AxisXYSquared*AxisY));
                        Projections2.push_back(Vector2((X22*AxisX+Y22*AxisY)/AxisXYSquared*AxisX, (X22*AxisX+Y22*AxisY)/AxisXYSquared*AxisY));
                        Projections2.push_back(Vector2((X23*AxisX+Y23*AxisY)/AxisXYSquared*AxisX, (X23*AxisX+Y23*AxisY)/AxisXYSquared*AxisY));
                        Projections2.push_back(Vector2((X24*AxisX+Y24*AxisY)/AxisXYSquared*AxisX, (X24*AxisX+Y24*AxisY)/AxisXYSquared*AxisY));

                        std::vector<float> Scalar1;
                        Scalar1.push_back(Projections1[0].X()*AxisX+Projections1[0].Y()*AxisY);
                        Scalar1.push_back(Projections1[1].X()*AxisX+Projections1[1].Y()*AxisY);
                        Scalar1.push_back(Projections1[2].X()*AxisX+Projections1[2].Y()*AxisY);
                        Scalar1.push_back(Projections1[3].X()*AxisX+Projections1[3].Y()*AxisY);

                        std::vector<float> Scalar2;
                        Scalar2.push_back(Projections2[0].X()*AxisX+Projections2[0].Y()*AxisY);
                        Scalar2.push_back(Projections2[1].X()*AxisX+Projections2[1].Y()*AxisY);
                        Scalar2.push_back(Projections2[2].X()*AxisX+Projections2[2].Y()*AxisY);
                        Scalar2.push_back(Projections2[3].X()*AxisX+Projections2[3].Y()*AxisY);

                        int Minimum1 = Vectors::FindMinimum(Scalar1);
                        int Maximum1 = Vectors::FindMaximum(Scalar1);
                        int Minimum2 = Vectors::FindMinimum(Scalar2);
                        int Maximum2 = Vectors::FindMaximum(Scalar2);

                        if (Scalar2[Minimum2] <= Scalar1[Maximum1] and Scalar2[Maximum2] >= Scalar1[Minimum1]) {
                            i++;

                            Vector2 Overlap1 = Vector2(Projections1[Maximum1].X()-Projections2[Minimum2].X(), Projections1[Maximum1].Y()-Projections2[Minimum2].Y());
                            Vector2 Overlap2 = Vector2(Projections2[Maximum2].X()-Projections1[Minimum1].X(), Projections2[Maximum2].Y()-Projections1[Minimum1].Y());

                            Vector2 NewAdjust;

                            if (Overlap1.Length2() > Overlap2.Length2()) NewAdjust = Overlap2; else NewAdjust = Overlap1;

                            /*
                            if (Adjust.X() and Adjust.Y()) {
                                if (NewAdjust.Length2() < Adjust.Length2()) {
                                    Adjust = NewAdjust;
                                }
                            } else {
                                Adjust = NewAdjust;
                            }
                            */
                        } else Overlap = false;
                    }

                    if (Overlap) {
                        RectangleInRectangle = true;
                        //AdjustX = Adjust.X();
                        //AdjustY = Adjust.Y();
                    } else {
                        AdjustX = AdjustY = 0;
                    }
                }
            } else {
                float AdjustX1 = (X1+Width1)-X2;
                float AdjustY1 = (Y1+Height1)-Y2;
                float AdjustX2 = (X2+Width2)-X1;
                float AdjustY2 = (Y2+Height2)-Y1;

                if (AdjustX1 > 0 && AdjustY1 > 0 && AdjustX2 > 0 && AdjustY2 > 0) {
                    RectangleInRectangle = true;

                    if (AdjustX1 < AdjustX2) AdjustX = AdjustX1; else AdjustX = -AdjustX2;
                    if (AdjustY1 < AdjustY2) AdjustY = AdjustY1; else AdjustY = -AdjustY2;
                }
            }

            return RectangleInRectangle;
        }

        /// Used to rotate a point around a center point by the specified angle.
        /** @param X1, Y1 Coordinates of the point.
            @param CenterX, CenterY Coordinates of the center point.
            @param Angle Direction (in radians) to which the point will be rotated. */
        void RotatePointBy(float &X1, float &Y1, float CenterX, float CenterY, float Angle) {
            float CurrentAngle = atan2(Y1-CenterY, X1-CenterX);
            float Radius = sqrt(pow(CenterX-X1, 2) +pow(CenterY-Y1, 2));
            X1 = CenterX+cosf(CurrentAngle+Angle)*Radius;
            Y1 = CenterY+sinf(CurrentAngle+Angle)*Radius;
        }
    }
}
