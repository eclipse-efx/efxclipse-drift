# Development Setup

## Build system

The project uses gradle to build the native and the java code. 

### Environment

#### Java
You need Java 8 with fx and Java 11 without fx.   
You can for example use the zulu packages:
 * jdk8fx: https://www.azul.com/downloads/zulu-community/?version=java-8-lts&architecture=x86-64-bit&package=jdk-fx
 * jdk11: https://www.azul.com/downloads/zulu-community/?version=java-11-lts&architecture=x86-64-bit&package=jdk

The following environment variables need to be set:
 * `JAVA_HOME_8` needs to point to a jdk8fx
 * `JAVA_HOME_11` needs to point to a jdk11
 * `JAVA_HOME` needs to point to the jdk11 for gradle to work

#### native code toolchains

### Project structure
The java code is split in 3 projects. This is needed since IDEs like eclipse only support one jdk per project.

 * `org.eclipse.fx.drift` the base project with most of the code
 * `org.eclipse.fx.drift.java8` the java8 only overlay
 * `org.eclipse.fx.drift.java11` the java11 only overlay

`./gradle buildMultireleaseJar` assembles the jar from those 3 projects.

 * `org.eclipse.fx.drift.native` contains the native code of driftfx
 * `native-driftcpp` contains the cpp binding
  
### IDEs

Gradle can generate the project files for many IDEs. 

examples:
```
  ./gradlew eclipse

  ./gradlew :org.eclipse.fx.drift.native:visualStudio
  ./gradlew :org.eclipse.fx.drift.native:xcode

```

