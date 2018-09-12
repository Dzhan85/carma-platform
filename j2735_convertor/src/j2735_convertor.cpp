
/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2017, Torc Robotics, LLC
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Torc Robotics, LLC nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#include "j2735_convertor.h"

// TODO top comment

int J2735Convertor::run() {
    initialize();
    return 0;
}

void J2735Convertor::initialize() {
  // TODO Setup node handles here if needed

  // Set Callback Queues for Node Handles
  bsm_nh_.setCallbackQueue(&bsm_queue_);
  spat_nh_.setCallbackQueue(&spat_queue_);
  map_nh_.setCallbackQueue(&map_queue_);

  // J2735 BSM Subscriber TODO figure out topic names
  j2735_bsm_sub_ = bsm_nh_.subscribe("j2735_incoming_bsm", 1000, &J2735Convertor::j2735BsmHandler, this);

  // BSM Publisher TODO think about queue sizes
  converted_bsm_pub_ = bsm_nh_.advertise<cav_msgs::BSM>("incoming_bsm", 1000);

  // J2735 SPAT Subscriber TODO figure out topic names
  j2735_spat_sub_ = spat_nh_.subscribe("j2735_incoming_spat", 1000, &J2735Convertor::j2735SpatHandler, this);

  // SPAT Publisher TODO think about queue sizes
  converted_spat_pub_ = spat_nh_.advertise<cav_msgs::SPAT>("incoming_spat", 1000);

  // J2735 MAP Subscriber TODO figure out topic names
  j2735_map_sub_ = map_nh_.subscribe("j2735_incoming_map", 1000, &J2735Convertor::j2735BsmHandler, this);

  // MAP Publisher TODO think about queue sizes
  converted_map_pub_ = map_nh_.advertise<cav_msgs::BSM>("incoming_map", 1000);

  // SystemAlert Subscriber
  system_alert_sub_ = default_nh_.subscribe("system_alert", 10, &J2735Convertor::systemAlertHandler, this);

  // SystemAlert Publisher
  system_alert_pub_ = default_nh_.advertise<cav_msgs::SystemAlert>("system_alert", 10);
}

void J2735Convertor::j2735BsmHandler(const j2735_msgs::BSMConstPtr& message) {

}

void J2735Convertor::j2735SpatHandler(const j2735_msgs::SPATConstPtr& message) {

}

void J2735Convertor::j2735MapHandler(const j2735_msgs::BSMConstPtr& message) {

}

void J2735Convertor::systemAlertHandler(const cav_msgs::SystemAlertConstPtr& message) {

}
