/**
 * @file    validation.h
 * @brief   Validation rules
 * @author  Bryan Bartley
 * @email   bartleyba@sbolstandard.org
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBOL.  Please visit http://sbolstandard.org for more
 * information about SBOL, and the latest version of libSBOL.
 *
 *  Copyright 2016 University of Washington, WA, USA
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ------------------------------------------------------------------------->*/

#ifndef VALIDATION_RULE_INCLUDED
#define VALIDATION_RULE_INCLUDED

#include <vector>
#include "config.h"

typedef void(*ValidationRule)(void *, void *);  // This defines the signature for validation rules.  The first argument is an SBOLObject, and the second argument is arbitrary data passed through to the handler function for validation
typedef std::vector<ValidationRule> ValidationRules;

namespace sbol
{
/* These validation rules are explicitly defined in the SBOL 2.0 specification document */

    SBOL_DECLSPEC void sbolRule10101(void *sbol_obj, void *arg);
	SBOL_DECLSPEC void sbolRule10102(void *sbol_obj, void *arg);
	SBOL_DECLSPEC void sbol_rule_10202(void *sbol_obj, void *arg);

/* These validation rules are internal to libSBOL */
    
    // Print a test message
	SBOL_DECLSPEC void libsbol_rule_1(void *sbol_obj, void *arg);
    
    // Validate XSD date-time format
    SBOL_DECLSPEC void libsbol_rule_2(void *sbol_obj, void *arg);
    
    // Validate Design.structure and Design.function are compatible
    SBOL_DECLSPEC void libsbol_rule_3(void *sbol_obj, void *arg);

    // Validate Design.structure and Design.function are compatible
    SBOL_DECLSPEC void libsbol_rule_4(void *sbol_obj, void *arg);

    bool is_alphanumeric_or_underscore(char c);
    
    bool is_not_alphanumeric_or_underscore(char c);


    //  The following class is an experimental wrapper class for a validation callback function
    //  See http://stackoverflow.com/questions/879408/c-function-wrapper-that-behaves-just-like-the-function-itself
    //
    //    class _ValidationRule
    //    {
    //    private:
    //        void (*validation_rule)(void *, void*);
    //    public:
    //        _ValidationRule(void (*validation_rule_arg)(void*, void*)) :
    //            validation_rule(validation_rule_arg)
    //        {
    //        };
    //        ~_ValidationRule();
    //    };
    
};


#endif