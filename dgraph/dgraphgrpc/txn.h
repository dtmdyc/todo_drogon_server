#ifndef DGRAPHGRPCTXN_H
#define DGRAPHGRPCTXN_H

#include <string>


#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "../dgraph-js/generated/api.grpc.pb.h"
#include "../dgraph-js/generated/api.pb.h"

//this will not work circular include:
//#include "./dgraphclient.h"

namespace dgraph {
namespace grpcclient {
class DgraphClient;

struct TxnOptions {
    bool readOnly = false;
    bool bestEffort = false;
};





/**
 * Txn is a single atomic transaction.
 *
 * A transaction lifecycle is as follows:
 *
 * 1. Created using Client.newTxn.
 *
 * 2. Various query and mutate calls made.
 *
 * 3. commit or discard used. If any mutations have been made, It's important
 * that at least one of these methods is called to clean up resources. discard
 * is a no-op if commit has already been called, so it's safe to call discard
 * after calling commit.
 */
class Txn
{
    DgraphClient *dc;
    //grpc::ClientContext *ctx;
    api::TxnContext ctx;
    bool finished = false;
    bool mutated = false;
    const bool useReadOnly = false;
    const bool useBestEffort = false;


public:

    Txn(DgraphClient *dc, TxnOptions txnOpts);



    /**
   * query sends a query to one of the connected Dgraph instances. If no
   * mutations need to be made in the same transaction, it's convenient to chain
   * the method, e.g. client.newTxn().query("...").
   */
    void query(std::string q, api::Response *response);

    /**
   * queryWithVars is like query, but allows a variable map to be used. This can
   * provide safety against injection attacks.
   */
    void queryWithVars(const std::string &q,
                       const std::map<std::string, std::string> &vars,
                       api::Response *response);

    /**
   * mutate allows data stored on Dgraph instances to be modified. The fields in
   * Mutation come in pairs, set and delete. Mutations can either be encoded as
   * JSON or as RDFs.
   *
   * If commitNow is set, then this call will result in the transaction being
   * committed. In this case, an explicit call to commit doesn't need to
   * subsequently be made.
   *
   * If the mutation fails, then the transaction is discarded and all future
   * operations on it will fail.
   */
    void mutate(api::Mutation &mu, api::Response* response);

    // void doRequest(Request req, std::function<void(Response)> callBack);

    /**
   * commit commits any mutations that have been made in the transaction. Once
   * commit has been called, the lifespan of the transaction is complete.
   *
   * Errors could be thrown for various reasons. Notably, ERR_ABORTED could be
   * thrown if transactions that modify the same data are being run
   * concurrently. It's up to the user to decide if they wish to retry. In this
   * case, the user should create a new transaction.
   */
    void doRequest(api::Request &req, api::Response *response);
    void commit(api::TxnContext *response);

    /**
   * discard cleans up the resources associated with an uncommitted transaction
   * that contains mutations. It is a no-op on transactions that have already
   * been committed or don't contain mutations. Therefore it is safe (and
   * recommended) to call it in a finally block.
   *
   * In some cases, the transaction can't be discarded, e.g. the grpc connection
   * is unavailable. In these cases, the server will eventually do the
   * transaction clean up.
   */
    void discard(api::TxnContext *response);
    void commitOrAbort(api::TxnContext *response);

private:
    void mergeContext(const api::TxnContext& src);
    std::string getPrintableMap(const std::map<std::string, std::string> &vars);
    std::string getPrintableMap(const google::protobuf::Map<std::string, std::string> &vars);



};





}
}
#endif // DGRAPHGRPCTXN_H
