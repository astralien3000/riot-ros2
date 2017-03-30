#ifndef LISTPARAMETERS_RESPONSE_DCPS_IMPL_H_
#define LISTPARAMETERS_RESPONSE_DCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_ListParameters_Response_.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "ccpp_DataReaderView_impl.h"


namespace rcl_interfaces {

    namespace srv {

        namespace dds_ {

            class  ListParameters_Response_TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
            {
            public:
                ListParameters_Response_TypeSupportFactory(const ListParameters_Response_TypeSupportFactory & o) = delete;
                ListParameters_Response_TypeSupportFactory & operator=(const ListParameters_Response_TypeSupportFactory & o) = delete;
                ListParameters_Response_TypeSupportFactory() {}
                virtual ~ListParameters_Response_TypeSupportFactory() {}
            private:
                ::DDS::DataWriter_ptr
                create_datawriter (gapi_dataWriter handle);
            
                ::DDS::DataReader_ptr
                create_datareader (gapi_dataReader handle);
            
                ::DDS::DataReaderView_ptr
                create_view (gapi_dataReaderView handle);
            };
            
            class  ListParameters_Response_TypeSupport : public virtual ListParameters_Response_TypeSupportInterface,
                                           public ::DDS::TypeSupport_impl
            {
            public:
                virtual ::DDS::ReturnCode_t register_type(
                    ::DDS::DomainParticipant_ptr participant,
                    const char * type_name) THROW_ORB_EXCEPTIONS;
            
                virtual char * get_type_name() THROW_ORB_EXCEPTIONS;
            
                ListParameters_Response_TypeSupport (void);
                virtual ~ListParameters_Response_TypeSupport (void);
            
            private:
                ListParameters_Response_TypeSupport (const ListParameters_Response_TypeSupport &);
                void operator= (const ListParameters_Response_TypeSupport &);
            
                static const char *metaDescriptor[];
                static const ::DDS::ULong metaDescriptorArrLength;
            };
            
            typedef ListParameters_Response_TypeSupportInterface_var ListParameters_Response_TypeSupport_var;
            typedef ListParameters_Response_TypeSupportInterface_ptr ListParameters_Response_TypeSupport_ptr;
            
            class  ListParameters_Response_DataWriter_impl : public virtual ListParameters_Response_DataWriter,
                                                public ::DDS::DataWriter_impl
            {
            public:
            
                virtual ::DDS::InstanceHandle_t register_instance(
                    const ListParameters_Response_ & instance_data) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::InstanceHandle_t register_instance_w_timestamp(
                    const ListParameters_Response_ & instance_data,
                    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t unregister_instance(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle,
                    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t write(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t write_w_timestamp(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle,
                    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t dispose(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t dispose_w_timestamp(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle,
                    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t writedispose(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t writedispose_w_timestamp(
                    const ListParameters_Response_ & instance_data,
                    ::DDS::InstanceHandle_t handle,
                    const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t get_key_value(
                    ListParameters_Response_ & key_holder,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::InstanceHandle_t lookup_instance(
                    const ListParameters_Response_ & instance_data) THROW_ORB_EXCEPTIONS;
            
            
                ListParameters_Response_DataWriter_impl (
                    gapi_dataWriter handle
                );
            
                virtual ~ListParameters_Response_DataWriter_impl (void);
            
            private:
                ListParameters_Response_DataWriter_impl(const ListParameters_Response_DataWriter_impl &);
                void operator= (const ListParameters_Response_DataWriter &);
            };
            
            class  ListParameters_Response_DataReader_impl : public virtual ListParameters_Response_DataReader,
                                                public ::DDS::DataReader_impl
            {
                friend class ListParameters_Response_DataReaderView_impl;
            public:
                virtual ::DDS::ReturnCode_t read(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_next_sample(
                    ListParameters_Response_ & received_data,
                    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_next_sample(
                    ListParameters_Response_ & received_data,
                    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_next_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_next_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t return_loan(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t get_key_value(
                    ListParameters_Response_ & key_holder,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::InstanceHandle_t lookup_instance(
                    const ListParameters_Response_ & instance) THROW_ORB_EXCEPTIONS;
            
                ListParameters_Response_DataReader_impl (
                    gapi_dataReader handle
                );
            
                virtual ~ListParameters_Response_DataReader_impl(void);
            
            private:
                ListParameters_Response_DataReader_impl(const ListParameters_Response_DataReader &);
                void operator= (const ListParameters_Response_DataReader &);
            
                static ::DDS::ReturnCode_t check_preconditions(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples
                );
            };
            
            class  ListParameters_Response_DataReaderView_impl : public virtual ListParameters_Response_DataReaderView,
                                                public ::DDS::DataReaderView_impl
            {
            public:
                virtual ::DDS::ReturnCode_t read(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_next_sample(
                    ListParameters_Response_ & received_data,
                    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_next_sample(
                    ListParameters_Response_ & received_data,
                    ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_next_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_next_instance(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::SampleStateMask sample_states,
                    ::DDS::ViewStateMask view_states,
                    ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t read_next_instance_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t take_next_instance_w_condition(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq,
                    ::DDS::Long max_samples,
                    ::DDS::InstanceHandle_t a_handle,
                    ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t return_loan(
                    ListParameters_Response_Seq & received_data,
                    ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::ReturnCode_t get_key_value(
                    ListParameters_Response_ & key_holder,
                    ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
            
                virtual ::DDS::InstanceHandle_t lookup_instance(
                    const ListParameters_Response_ & instance) THROW_ORB_EXCEPTIONS;
            
                ListParameters_Response_DataReaderView_impl (
                    gapi_dataReader handle
                );
            
                virtual ~ListParameters_Response_DataReaderView_impl(void);
            
            private:
                ListParameters_Response_DataReaderView_impl(const ListParameters_Response_DataReaderView &);
                void operator= (const ListParameters_Response_DataReaderView &);
            };
            
        }

    }

}

#endif
