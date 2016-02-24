/*
 * ImageProcess.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: NinjaPC
 */

#include <ImageProcess.h>
#include <vector>
#include <cmath>
ImageProcess::ImageProcess() {
	// TODO Auto-generated constructor stub

}

ImageProcess::~ImageProcess() {
	// TODO Auto-generated destructor stub
}

 bool ImageProcess::CompareParticleSizes(ParticleReport particle1, ParticleReport particle2)
{
	//we want descending sort order
	return particle1.PercentAreaToImageArea > particle2.PercentAreaToImageArea;
}
double ImageProcess:: ratioToScore(double ratio)
{
	return (fmax(0, fmin(100*(1-fabs(1-ratio)), 100)));
}
double ImageProcess :: AreaScore(ParticleReport report)
{
	double boundingArea = (report.BoundingRectBottom - report.BoundingRectTop) * (report.BoundingRectRight - report.BoundingRectLeft);

	return ratioToScore((49/24)*report.Area/boundingArea);
}
double ImageProcess :: AspectScore(ParticleReport report)
{
	return ratioToScore(((report.BoundingRectRight-report.BoundingRectLeft)/(report.BoundingRectBottom-report.BoundingRectTop)));
}
double ImageProcess::computeDistance (Image *image, ParticleReport report) {
		double normalizedWidth, targetWidth;
		int xRes, yRes;

		imaqGetImageSize(image, &xRes, &yRes);
		normalizedWidth = 2*(report.BoundingRectRight - report.BoundingRectLeft)/xRes;
		SmartDashboard::PutNumber("Width", normalizedWidth);
		targetWidth = 7;

		return  targetWidth/(normalizedWidth*12*tan(VIEW_ANGLE*M_PI/(180*2)));
	}