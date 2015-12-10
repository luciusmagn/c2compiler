/* Copyright 2013-2015 Bas van den Berg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CODEGEN_INTERFACE_GENERATOR_H
#define CODEGEN_INTERFACE_GENERATOR_H

#include <string>
#include <vector>

#include "Utils/StringBuilder.h"

namespace C2 {

class AST;
class Decl;
class VarDecl;
class TypeDecl;
class FunctionDecl;
class ImportDecl;
class StructTypeDecl;
class FunctionTypeDecl;
class EnumTypeDecl;
class QualType;
class Expr;
class Stmt;
class CompoundStmt;
class HeaderNamer;

class InterfaceGenerator {
public:
    InterfaceGenerator(const std::string& moduleName_);
    ~InterfaceGenerator() {}

    void addEntry(AST& ast) { entries.push_back(&ast); }

    void write(const std::string& outputDir, bool printCode);

private:
    void EmitImport(const ImportDecl* D);
    void EmitTypeDecl(const TypeDecl* D);
    void EmitVarDecl(const VarDecl* D, unsigned indent);
    void EmitFunctionDecl(const FunctionDecl* D);

    void EmitFunctionArgs(const FunctionDecl* F);
    void EmitArgVarDecl(const VarDecl* D, unsigned index);

    void EmitType(QualType type);
    void EmitAliasType(const TypeDecl* T);
    void EmitStructType(const StructTypeDecl* S, unsigned indent);
    void EmitEnumType(const EnumTypeDecl* E);
    void EmitFunctionType(const FunctionTypeDecl* F);

    void EmitExpr(const Expr* E, StringBuilder& output);
    void EmitBinaryOperator(const Expr* E, StringBuilder& output);
    void EmitConditionalOperator(const Expr* E, StringBuilder& output);
    void EmitUnaryOperator(const Expr* E, StringBuilder& output);
    void EmitMemberExpr(const Expr* E, StringBuilder& output);
    void EmitCallExpr(const Expr* E, StringBuilder& output);
    void EmitIdentifierExpr(const Expr* E, StringBuilder& output);
    void EmitBitOffsetExpr(const Expr* Base, Expr* E, StringBuilder& output);

    // Helpers
    void EmitStringLiteral(const std::string& input, StringBuilder& output);
    void EmitAttributes(const Decl* D);

    bool EmitAsStatic(const Decl* D) const;

    const std::string moduleName;

    typedef std::vector<AST*> Entries;
    typedef Entries::iterator EntriesIter;
    Entries entries;

    StringBuilder iface;

    InterfaceGenerator(const InterfaceGenerator&);
    InterfaceGenerator& operator= (const InterfaceGenerator&);
};

}

#endif

