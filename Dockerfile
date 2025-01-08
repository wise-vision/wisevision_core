FROM ros:humble-ros-base

WORKDIR /root/wisevision_core_ws

COPY  . /root/wisevision_core_ws/src/wisevision_core

RUN /bin/bash -c "source /opt/ros/$ROS_DISTRO/setup.bash && \
    cd /root/wisevision_core_ws && \
    colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release"

ENTRYPOINT ["/bin/bash", "-c", " \
    source /opt/ros/$ROS_DISTRO/setup.bash && \
    source /root/wisevision_core_ws/install/setup.bash && \
    bash"]