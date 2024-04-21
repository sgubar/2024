typedef struct tagColorProps {
    float red;
    float green;
    float blue;
} ColorProps;

typedef struct tagStage {
    ColorProps curve;
    ColorProps coords;
    ColorProps back;

    float coordStep;
    float curveStep;

    float centerX;
    float centerY;

    void (*func_t)(float *, float *, float);
    float maxT;
    float minT;
} Stage;

void displayFuncT(void);
void attachMathFunc(void (*funcPtr)(float *, float *, float), float minT, float maxT);
void setCenter(float centerX, float centerY);
void setSteps(float coordStep, float curveStep);
void setCurveColor(unsigned char r, unsigned char g, unsigned char b);
void setBackColor(unsigned char r, unsigned char g, unsigned char b);
void setCoordsColor(unsigned char r, unsigned char g, unsigned char b);
