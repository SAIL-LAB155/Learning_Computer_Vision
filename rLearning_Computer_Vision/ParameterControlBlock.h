#ifndef PARAMETERCONTROLBLOCK_H
#define PARAMETERCONTROLBLOCK_H

#include <QApplication>

typedef enum
{
    Module_Fruit = 0,
    Module_Creatures,
    Module_Cat_and_Dog,
    Module_Vehicles,
    Module_Human,

    Module_Max
}Module_t;

class ParameterControlBlock
{
public:
    ParameterControlBlock();

	void Set_isTrainOkay(bool okay);
	bool Get_isTrainOkay(void);

    void Set_ModuleIndex(Module_t);
    uint8_t Get_ModuleIndex(void);

	void Set_ImagePath(QString&);
	QString& Get_ImagePath(void);

	void Set_ModelPath(QString&);
	QString& Get_ModelPath(void);

	void Set_Visualization_ImagePath(QString&);
	QString& Get_Visualization_ImagePath(void);

	void Set_Visualization_ModelPath(QString&);
	QString& Get_Visualization_ModelPath(void);

	void Set_Visualization_OpenImagePath(QString&);
	QString& Get_Visualization_OpenImagePath(void);

private:
	bool m_isTrainOkay;
    Module_t m_ModuleIndex;
	QString m_ImagePath;
	QString m_ModelPath;

	QString m_Visualization_ImagePath;
	QString m_Visualization_ModelPath;
	QString m_Visualization_OpenImagePath;
};

extern ParameterControlBlock ParaCB;

#endif // PARAMETERCONTROLBLOCK_H
