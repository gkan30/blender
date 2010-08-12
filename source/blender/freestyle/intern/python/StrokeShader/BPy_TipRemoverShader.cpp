#include "BPy_TipRemoverShader.h"

#include "../../stroke/BasicStrokeShaders.h"

#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////////////////

//------------------------INSTANCE METHODS ----------------------------------

static char TipRemoverShader___doc__[] =
"Class hierarchy: :class:`StrokeShader` > :class:`TipRemoverShader`\n"
"\n"
"[Geometry shader]\n"
"\n"
".. method:: __init__(tipLength)\n"
"\n"
"   Builds a TipRemoverShader object.\n"
"\n"
"   :arg tipLength: The length of the piece of stroke we want to remove\n"
"      at each extremity.\n"
"   :type tipLength: float\n"
"\n"
".. method:: shade(s)\n"
"\n"
"   Removes the stroke's extremities.\n"
"\n"
"   :arg s: A Stroke object.\n"
"   :type s: :class:`Stroke`\n";

static int TipRemoverShader___init__( BPy_TipRemoverShader* self, PyObject *args)
{
	double d;

	if(!( PyArg_ParseTuple(args, "d", &d) ))
		return -1;

	self->py_ss.ss = new StrokeShaders::TipRemoverShader(d);
	return 0;
}

/*-----------------------BPy_TipRemoverShader type definition ------------------------------*/

PyTypeObject TipRemoverShader_Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"TipRemoverShader",             /* tp_name */
	sizeof(BPy_TipRemoverShader),   /* tp_basicsize */
	0,                              /* tp_itemsize */
	0,                              /* tp_dealloc */
	0,                              /* tp_print */
	0,                              /* tp_getattr */
	0,                              /* tp_setattr */
	0,                              /* tp_reserved */
	0,                              /* tp_repr */
	0,                              /* tp_as_number */
	0,                              /* tp_as_sequence */
	0,                              /* tp_as_mapping */
	0,                              /* tp_hash  */
	0,                              /* tp_call */
	0,                              /* tp_str */
	0,                              /* tp_getattro */
	0,                              /* tp_setattro */
	0,                              /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
	TipRemoverShader___doc__,       /* tp_doc */
	0,                              /* tp_traverse */
	0,                              /* tp_clear */
	0,                              /* tp_richcompare */
	0,                              /* tp_weaklistoffset */
	0,                              /* tp_iter */
	0,                              /* tp_iternext */
	0,                              /* tp_methods */
	0,                              /* tp_members */
	0,                              /* tp_getset */
	&StrokeShader_Type,             /* tp_base */
	0,                              /* tp_dict */
	0,                              /* tp_descr_get */
	0,                              /* tp_descr_set */
	0,                              /* tp_dictoffset */
	(initproc)TipRemoverShader___init__, /* tp_init */
	0,                              /* tp_alloc */
	0,                              /* tp_new */
};

///////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
