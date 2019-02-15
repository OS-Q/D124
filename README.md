# W28：[身份管控](https://github.com/OS-Q/W28)

[![sites](OS-Q/OS-Q.png)](http://www.OS-Q.com)

#### 归属边缘管控：[M7](https://github.com/OS-Q/M7)

#### 关于系统架构：[OS-Q](https://github.com/OS-Q/OS-Q)

## [平台描述](https://github.com/OS-Q/W28/wiki) 

身份管控核环境部署平台，用于管理各个边缘设备的身份和功能初始定义，构建自适应的网络环境

### [共用资源](OS-Q/)



---

- 边缘设备命名规则：体系 Q:[1,4] -> 节点 M:[1,12] -> 平台 W:[1,52] -> 设备 D:[1,365]

- naming patterns：system Q[1,4] -> node M[1,12] -> platform W[1,52] -> device D[1,365]

## [包含设备](https://github.com/OS-Q/W28/wiki) 

#### D190：[存储更新](https://github.com/OS-Q/D190)

通过SD转移和传递固件烧录信息，实现初始构建

#### D191：[串口更新](https://github.com/OS-Q/D191)

通过串口接入设备实现固件管控，实现初始构建

#### D192：[烧录设备](https://github.com/OS-Q/D192)

通过标准的扩展接口实现boot固件在线烧录管理

#### D193：[NULL](https://github.com/OS-Q/D193)



#### D194：[NULL](https://github.com/OS-Q/D194)



#### D195：[NULL](https://github.com/OS-Q/D195)



#### D196：[NULL](https://github.com/OS-Q/D196)


## [同级平台](https://github.com/OS-Q/M7/wiki) 

#### W27：[状态管控](https://github.com/OS-Q/W27)

用于管理和控制下辖所有的节点设备的生存状态

#### -> W28：[身份管控](https://github.com/OS-Q/W28)

用于管理和控制下辖所有节点的功能和初始配置

#### W29：[业务管控](https://github.com/OS-Q/W29)

用于管理和控制下辖所有节点的功能和业务逻辑

#### W30：[信息管控](https://github.com/OS-Q/W30)

用于管理呈现边缘体系信息，完成和用户间交互

---

####  © qitas@qitas.cn
###  [OS-Q redefined Operation System](http://www.OS-Q.com)
####  @ 2019-1-14

