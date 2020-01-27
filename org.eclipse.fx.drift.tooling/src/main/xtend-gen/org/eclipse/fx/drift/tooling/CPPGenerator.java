package org.eclipse.fx.drift.tooling;

import java.util.List;
import org.eclipse.fx.drift.tooling.Command;
import org.eclipse.fx.drift.tooling.Param;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.xbase.lib.Conversions;
import org.eclipse.xtext.xbase.lib.IterableExtensions;
import org.eclipse.xtext.xbase.lib.StringExtensions;

@SuppressWarnings("all")
public class CPPGenerator {
  public static String getClassPackage(final String javaClass) {
    String[] parts = javaClass.split("[.]");
    final String[] _converted_parts = (String[])parts;
    int _length = parts.length;
    int _minus = (_length - 1);
    List<String> parts2 = ((List<String>)Conversions.doWrapArray(_converted_parts)).subList(0, _minus);
    return IterableExtensions.join(parts2, ".");
  }
  
  public static String getClassName(final String javaClass) {
    String[] parts = javaClass.split("[.]");
    int _length = parts.length;
    int _minus = (_length - 1);
    return parts[_minus];
  }
  
  public static String getJNIMethodNamespace(final String javaClass) {
    return javaClass.replaceAll("[.]", "_");
  }
  
  public CharSequence generateJavaParameterList(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("(");
    {
      boolean _hasElements = false;
      for(final Param p : c.params) {
        if (!_hasElements) {
          _hasElements = true;
        } else {
          _builder.appendImmediate(", ", "");
        }
        _builder.append(p.type);
        _builder.append(" ");
        _builder.append(p.name);
      }
    }
    _builder.append(")");
    return _builder;
  }
  
  public CharSequence generateJniJava(final String javaClass, final List<org.eclipse.fx.drift.tooling.Enum> enums, final List<Command> commands) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("package ");
    String _classPackage = CPPGenerator.getClassPackage(javaClass);
    _builder.append(_classPackage);
    _builder.append(";");
    _builder.newLineIfNotEmpty();
    _builder.newLine();
    _builder.append("public final class ");
    String _className = CPPGenerator.getClassName(javaClass);
    _builder.append(_className);
    _builder.append(" {");
    _builder.newLineIfNotEmpty();
    _builder.append("\t");
    _builder.newLine();
    {
      for(final org.eclipse.fx.drift.tooling.Enum e : enums) {
        _builder.append("\t");
        _builder.append("public static final int ");
        _builder.append(e.name, "\t");
        _builder.append(" = ");
        _builder.append(e.value, "\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t");
    _builder.newLine();
    {
      for(final Command c : commands) {
        _builder.append("\t");
        _builder.append("public static native ");
        _builder.append(c.type, "\t");
        _builder.append(" ");
        _builder.append(c.name, "\t");
        CharSequence _generateParameterList = this.generateParameterList(c);
        _builder.append(_generateParameterList, "\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    return _builder;
  }
  
  public CharSequence generateJniCPP(final String javaClass, final List<org.eclipse.fx.drift.tooling.Enum> enums, final List<Command> commands) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("#include <jni.h>");
    _builder.newLine();
    _builder.newLine();
    _builder.append("extern \"C\" {");
    _builder.newLine();
    _builder.append("\t");
    _builder.newLine();
    {
      for(final Command c : commands) {
        _builder.append("\t");
        _builder.append("extern \"C\" JNIEXPORT ");
        String _jniCType = CPPGenerator.getJniCType(c);
        _builder.append(_jniCType, "\t");
        _builder.append(" JNICALL Java_");
        String _jNIMethodNamespace = CPPGenerator.getJNIMethodNamespace(javaClass);
        _builder.append(_jNIMethodNamespace, "\t");
        _builder.append("_");
        _builder.append(c.name, "\t");
        String _jniCParameterList = CPPGenerator.getJniCParameterList(c);
        _builder.append(_jniCParameterList, "\t");
        _builder.append(" {");
        _builder.newLineIfNotEmpty();
        _builder.append("\t");
        _builder.append("\t");
        _builder.append("driftgl::");
        _builder.append(c.name, "\t\t");
        String _jniCParameterCallList = CPPGenerator.getJniCParameterCallList(c);
        _builder.append(_jniCParameterCallList, "\t\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
        _builder.append("\t");
        _builder.append("}");
        _builder.newLine();
        _builder.append("\t");
        _builder.append("\t");
        _builder.newLine();
        _builder.append("\t");
        _builder.append("public static native ");
        _builder.append(c.type, "\t");
        _builder.append(" ");
        _builder.append(c.name, "\t");
        CharSequence _generateParameterList = this.generateParameterList(c);
        _builder.append(_generateParameterList, "\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    return _builder;
  }
  
  public static String getJniCType(final Command c) {
    final String _switchValue = c.type;
    boolean _matched = false;
    return ("/*TODO*/ " + c.type);
  }
  
  public static String getJniCParameterList(final Command c) {
    return ("(" + ")");
  }
  
  public static String getJniCParameterCallList(final Command c) {
    return ("(" + ")");
  }
  
  public CharSequence generateHeader(final List<org.eclipse.fx.drift.tooling.Enum> enums, final List<Command> commands) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.newLine();
    _builder.append("#ifndef GL_CONTEXT_GEN_H_");
    _builder.newLine();
    _builder.append("#define GL_CONTEXT_GEN_H_");
    _builder.newLine();
    _builder.newLine();
    _builder.append("#include <cstdint>");
    _builder.newLine();
    _builder.newLine();
    _builder.append("namespace driftgl {");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef void GLvoid;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned int GLenum;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef float GLfloat;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef int GLint;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef int GLsizei;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned int GLbitfield;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef double GLdouble;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned int GLuint;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned char GLboolean;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned char GLubyte;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef char GLchar;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef short GLshort;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef signed char GLbyte;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned short GLushort;");
    _builder.newLine();
    _builder.append("\t");
    _builder.newLine();
    _builder.append("\t");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef unsigned short GLhalf;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef struct __GLsync *GLsync;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef uint64_t GLuint64;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef int64_t GLint64;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef ptrdiff_t GLsizeiptr;");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef ptrdiff_t GLintptr;");
    _builder.newLine();
    _builder.append("\t");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("typedef void (*GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);");
    _builder.newLine();
    _builder.append("\t");
    _builder.newLine();
    _builder.append("\t");
    _builder.newLine();
    {
      for(final org.eclipse.fx.drift.tooling.Enum e : enums) {
        _builder.append("\t");
        _builder.append("extern unsigned int ");
        _builder.append(e.name, "\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t");
    _builder.newLine();
    {
      for(final Command c : commands) {
        _builder.append("\t");
        CharSequence _generateAPICall = this.generateAPICall(c);
        _builder.append(_generateAPICall, "\t");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("namespace procs {");
    _builder.newLine();
    _builder.append("\t\t");
    _builder.append("typedef void* (LookupFunctionPointer(const char* functionName));");
    _builder.newLine();
    _builder.append("\t\t");
    _builder.append("void Initialize(LookupFunctionPointer lookupFunctionPointer);");
    _builder.newLine();
    _builder.append("\t");
    _builder.append("}");
    _builder.newLine();
    _builder.append("}");
    _builder.newLine();
    _builder.newLine();
    _builder.append("#endif");
    _builder.newLine();
    return _builder;
  }
  
  public CharSequence generateSource(final List<org.eclipse.fx.drift.tooling.Enum> enums, final List<Command> commands) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.newLine();
    _builder.append("\t");
    _builder.append("#include \"DriftGL_gen.h\"");
    _builder.newLine();
    _builder.newLine();
    _builder.append("\t");
    _builder.append("namespace driftgl {");
    _builder.newLine();
    _builder.append("\t\t\t\t");
    _builder.newLine();
    {
      for(final org.eclipse.fx.drift.tooling.Enum e : enums) {
        _builder.append("\t\t");
        _builder.append("unsigned int ");
        _builder.append(e.name, "\t\t");
        _builder.append(" = ");
        _builder.append(e.value, "\t\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t\t");
    _builder.newLine();
    _builder.append("\t\t");
    _builder.append("namespace procs {");
    _builder.newLine();
    {
      for(final Command c : commands) {
        _builder.append("\t\t\t");
        CharSequence _generateProcTypedef = this.generateProcTypedef(c);
        _builder.append(_generateProcTypedef, "\t\t\t");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t\t\t");
    _builder.newLine();
    {
      for(final Command c_1 : commands) {
        _builder.append("\t\t\t");
        CharSequence _procDef = CPPGenerator.toProcDef(c_1);
        _builder.append(_procDef, "\t\t\t");
        _builder.append(" ");
        CharSequence _procVar = CPPGenerator.toProcVar(c_1);
        _builder.append(_procVar, "\t\t\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t\t\t");
    _builder.newLine();
    _builder.append("\t\t\t");
    _builder.append("void Initialize(LookupFunctionPointer lookupFunctionPointer) {");
    _builder.newLine();
    {
      for(final Command c_2 : commands) {
        _builder.append("\t\t\t\t");
        CharSequence _procVar_1 = CPPGenerator.toProcVar(c_2);
        _builder.append(_procVar_1, "\t\t\t\t");
        _builder.append(" = (");
        CharSequence _procDef_1 = CPPGenerator.toProcDef(c_2);
        _builder.append(_procDef_1, "\t\t\t\t");
        _builder.append(")lookupFunctionPointer(\"");
        _builder.append(c_2.name, "\t\t\t\t");
        _builder.append("\");");
        _builder.newLineIfNotEmpty();
      }
    }
    _builder.append("\t\t\t");
    _builder.append("}");
    _builder.newLine();
    _builder.append("\t\t\t");
    _builder.newLine();
    _builder.append("\t\t");
    _builder.append("}");
    _builder.newLine();
    _builder.append("\t\t");
    _builder.newLine();
    {
      for(final Command c_3 : commands) {
        _builder.append("\t\t");
        _builder.append(c_3.type, "\t\t");
        _builder.append(" ");
        _builder.append(c_3.name, "\t\t");
        CharSequence _generateParameterList = this.generateParameterList(c_3);
        _builder.append(_generateParameterList, "\t\t");
        _builder.append(" {");
        _builder.newLineIfNotEmpty();
        _builder.append("\t\t");
        _builder.append("\t");
        _builder.append("return procs::");
        CharSequence _procVar_2 = CPPGenerator.toProcVar(c_3);
        _builder.append(_procVar_2, "\t\t\t");
        CharSequence _generateParameterCall = this.generateParameterCall(c_3);
        _builder.append(_generateParameterCall, "\t\t\t");
        _builder.append(";");
        _builder.newLineIfNotEmpty();
        _builder.append("\t\t");
        _builder.append("}");
        _builder.newLine();
      }
    }
    _builder.append("\t");
    _builder.append("}");
    _builder.newLine();
    return _builder;
  }
  
  public static CharSequence toProcVar(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("pfn");
    String _firstUpper = StringExtensions.toFirstUpper(c.name);
    _builder.append(_firstUpper);
    return _builder;
  }
  
  public static CharSequence toProcDef(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("PFN");
    String _upperCase = c.name.toUpperCase();
    _builder.append(_upperCase);
    return _builder;
  }
  
  public CharSequence generateAPICall(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append(c.type);
    _builder.append(" ");
    _builder.append(c.name);
    CharSequence _generateParameterList = this.generateParameterList(c);
    _builder.append(_generateParameterList);
    _builder.append(";");
    _builder.newLineIfNotEmpty();
    return _builder;
  }
  
  public CharSequence generateParameterList(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("(");
    {
      boolean _hasElements = false;
      for(final Param p : c.params) {
        if (!_hasElements) {
          _hasElements = true;
        } else {
          _builder.appendImmediate(", ", "");
        }
        _builder.append(p.type);
        _builder.append(" ");
        _builder.append(p.name);
      }
    }
    _builder.append(")");
    return _builder;
  }
  
  public CharSequence generateParameterCall(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("(");
    {
      boolean _hasElements = false;
      for(final Param p : c.params) {
        if (!_hasElements) {
          _hasElements = true;
        } else {
          _builder.appendImmediate(", ", "");
        }
        _builder.append(p.name);
      }
    }
    _builder.append(")");
    return _builder;
  }
  
  public CharSequence generateProcTypedef(final Command c) {
    StringConcatenation _builder = new StringConcatenation();
    _builder.append("typedef ");
    _builder.append(c.type);
    _builder.append(" (* ");
    CharSequence _procDef = CPPGenerator.toProcDef(c);
    _builder.append(_procDef);
    _builder.append(") ");
    CharSequence _generateParameterList = this.generateParameterList(c);
    _builder.append(_generateParameterList);
    _builder.append(";");
    _builder.newLineIfNotEmpty();
    return _builder;
  }
}
