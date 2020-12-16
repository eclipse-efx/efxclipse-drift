# Development Setup

## Build system

The project uses gradle to build the native and the java code. Java 11 is required for gradle to run (there is at least one gradle plugin which depends on Java 11). For the native build gradle uses the locally installed native toolchains.

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

##### Windows

 * Java 11 
 * Visual Studio 2019 with the nativedesktop workload 

Setup example using chocolatey on Windows 10

```
choco install zulu --version=11.29.11
choco install visualstudio2019community --norestart
choco install visualstudio2019-workload-nativedesktop --norestart
```

##### Linux

 * Java 11
 * g++
 * mesa dev headers

Setup example using ubuntu 20.04

```
apt-get install openjdk-11-jdk
apt-get install g++
apt-get install mesa-common-dev
```

##### MacOS

 * Java 11
 * Xcode
 

### Project structure
The java code is split in 3 projects. This is needed since IDEs like eclipse only support one jdk per project.

 * `org.eclipse.fx.drift` the base project with most of the code
 * `org.eclipse.fx.drift.java8` the java8 only overlay
 * `org.eclipse.fx.drift.java11` the java11 only overlay

The gradle command `./gradlew buildMultireleaseJar` assembles the jar from those 3 projects.

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

#### Eclipse

Recommended Plugins
 * EGit
 * Buildship
 * JDT
 
Configure both the Java 8 and the Java 11 SDKs as Installed JREs in Eclipse. To do so navigate to `Preferences -> Java -> Installed JREs` and add them. Also make sure that that the Execution Environments are setup correctly. JavaSE-1.8 needs to point to your Java 8 SDK and JavaSE-11 needs to point to your Java 11 SDK.    
This step is required since we create a multirelease jar and in eclipse each project may only have one SDK.
 
Now you can import the projects into Eclipse. Use the Import Gradle project wizard from Buildship.

You should get the following projects:

 * `driftfx-root`
 * `native-driftcpp`
 * `org.eclipse.fx.drift`
 * `org.eclipse.fx.drift.java11`
 * `org.eclipse.fx.drift.java8`
 * `org.eclipse.fx.drift.native`
 
### Building

##### JNI

The native part of drift resides in `org.eclipse.fx.drift.native`. To build it execute

```sh
./gradlew :org.eclipse.fx.drift.native:publish`
```

This builds and publishes the native libs of your platform into `./native-repo`. The `copyNatives` tasks copies them over to `org.eclipse.fx.drift/src/main/resources/native`


##### Java

To build the drift multirelease jar execute

```sh
./gradlew buildMultireleaseJar
```

The jar will be generated to `build/libs/org.eclipse.fx.drift.jar`.

This target depends on building the common code (`org.eclipse.fx.drift`), the Java 8 Layer (`org.eclipse.fx.drift.java8`), the Java 11 Layer (`org.eclipse.fx.drift.java11`) and packages them together into a [Multi-Release JAR](https://openjdk.java.net/jeps/238). 

The native libraries are expected to be in `org.eclipse.fx.drift/src/main/resources/native` to be included in the JAR.
The `copyNatives` task is invoked by `buildMultireleaseJar` and copies all available natives from the `./native-repo`. 

##### Building a p2 update site locally

There are two tasks to create the p2 update site. `updateSite` creates the update site as expanded directory, while `updateSiteZip` creates it as zip archive.

```sh
./gradlew updateSite
./gradlew updateSiteZip
```

Those tasks have no direct dependency on `buildMultireleaseJar` because they can either work with the signed or the unsigned version. The signed version is used for the build pipeline on github. If you want to use a signed version yourself you have to provide it in `./build/signed/org.eclipse.fx.drift.jar` and set the property useSignedArtifacts (e.g. `./gradlew -PuseSignedArtifacts updateSite`).    
Otherwise the locally built `./build/libs/org.eclipse.fx.drift.jar` is used.

The resulting update site is generated into `./build/updatesite/` or `./build/updatesite.zip` respectively.






 




